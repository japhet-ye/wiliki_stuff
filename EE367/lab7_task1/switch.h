/*
 * switch.h
 */

struct switch_fwd {
	int valid;	// valid flag
	char dest;	// destination host ID
	int port;	// port number
	int localRootID; 
	int localRootDist;
	char localParent;
	char localPortTree[100];
};

void switch_main(int switch_id);


