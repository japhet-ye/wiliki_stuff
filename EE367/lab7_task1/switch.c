/*
  * switch.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <unistd.h>
#include <fcntl.h>

#include "main.h"
#include "net.h"
#include "man.h"
#include "host.h"
#include "switch.h"
#include "packet.h"

#define MAX_FILE_BUFFER 1000
#define MAX_MSG_LENGTH 100
#define MAX_DIR_NAME 100
#define MAX_FILE_NAME 100
#define PKT_PAYLOAD_MAX 100
#define TENMILLISEC 10000   /* 10 millisecond sleep */
#define MAX_FWD_LENGTH 100

/*
 *  Main
 */

void switch_main(int switch_id){
char dir[MAX_DIR_NAME];
int dir_valid = 0;

char man_msg[MAN_MSG_LENGTH];
char man_reply_msg[MAN_MSG_LENGTH];
char man_cmd;

struct net_port *node_port_list;
struct net_port **node_port;  // Array of pointers to node ports
int node_port_num;            // Number of node ports

int ping_reply_received;
int i, k, n;
int dst;
char name[MAX_FILE_NAME];
char string[PKT_PAYLOAD_MAX+1];

FILE *fp;

struct packet *in_packet; /* Incoming packet */
struct packet *new_packet;

struct net_port *p;
struct host_job *new_job;
struct host_job *new_job2;

struct job_queue job_q;

struct switch_fwd fwdtab[MAX_FWD_LENGTH];

int localRootID = switch_id;
int localRootDist = 0;
int localParent = 0;
int localPortTree[100] = {0};

//Initially set all valid id's on forwarding table to 0 (max table size is 100)
for (int i=0; i<MAX_FWD_LENGTH; i++){
	fwdtab[i].valid = 0;
}


//Sasaki code from host.c
	/*
	* Create an array node_port[ ] to store the network link ports
	* at the host.  The number of ports is node_port_num
	*/
	node_port_list = net_get_port_list(switch_id);

		/*  Count the number of network link ports */
	node_port_num = 0;
	for (p=node_port_list; p!=NULL; p=p->next) {
		node_port_num++;
	}
		/* Create memory space for the array */
	node_port = (struct net_port **) 
		malloc(node_port_num*sizeof(struct net_port *));

		/* Load ports into the array */
	p = node_port_list;
	for (k = 0; k < node_port_num; k++) {
		node_port[k] = p; 
		p = p->next;
	}	

	/* Initialize the job queue */
	job_q_init(&job_q);


while(1){
	//If packet is a tree packet, do sasaki's code
	if (in_packet->type == PKT_TREE_DISCOVERY){
		if (in_packet -> SenderType == 'S'){
			if (in_packet -> RootID < localRootID){
				localRootID = in_packet ->RootID;
				localParent = k;
				localRootDist = in_packet ->RootDist +1;
			}
			else if(in_packet ->RootID == localRootID){
				if (localRootDist > in_packet ->RootDist + 1){
					localParent = k;
					localRootDist = in_packet ->RootDist + 1;
				}
			}
		}
		
		if (in_packet ->SenderType == 'H'){
			localPortTree[k] = 1;
		}
		else if (in_packet ->SenderChild = 'Y'){
			localPortTree[k] = 1;
		}
		else
			localPortTree[k] = 0;
	}
	for (int iterator = 0; iterator < 100; iterator ++) {
		if (localPortTree[iterator] == 1){
			//Code for adding jobs from host.c code
	for (k = 0; k < node_port_num; k++) { /* Scan all ports */

			in_packet = (struct packet *) malloc(sizeof(struct packet));
			n = packet_recv(node_port[k], in_packet);

			if (n > 0) {
				new_job = (struct host_job *)
					malloc(sizeof(struct host_job));
				new_job->in_port_index = k;
				new_job->packet = in_packet;
				job_q_add(&job_q, new_job);
			}
			else {
				free(in_packet);
			}
		}
	if (job_q_num(&job_q) > 0) {
		new_job = job_q_remove(&job_q); //Dequeue a job and set as new job
		int validport = -10000;
		
	
		for(int x =0; x<MAX_FWD_LENGTH; x++){
			if(fwdtab[i].valid && fwdtab[i].dest == new_job->packet->src){
			validport = fwdtab[i].port;
			break;
			}
		}

		if (validport == -10000) //Valid port was not found, need to add to table
			{
				for (int c=0; c<MAX_FWD_LENGTH; c++)
				{
					if (fwdtab[c].valid == 0)
					{
						fwdtab[c].valid = 1;
						fwdtab[c].dest = new_job->packet->src;
						fwdtab[c].port = new_job->in_port_index;
						validport = fwdtab[c].port;
						break;
					}
				}
			}

			validport = -10000; //reset unknown port flag

			for (int c=0; c<MAX_FWD_LENGTH; c++) //Iterate to check & send packet according to forwarding table entry
			{
				if (fwdtab[c].valid && fwdtab[c].dest == new_job->packet->dst)
				{
					validport = fwdtab[c].port;
					break;
				}
			}

			if (validport > -10000) //if port is valid but not known
			{
				packet_send(node_port[validport], new_job->packet);
			}
			else
			{
				for (k=0; k<node_port_num; k++)
				{
					if (k != new_job->in_port_index) {
						packet_send(node_port[k], new_job->packet);
					}
				}
			}

			free(new_job->packet);
			free(new_job);

		}


			}
		}
	}

}












