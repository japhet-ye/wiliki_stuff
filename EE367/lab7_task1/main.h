
#define BCAST_ADDR 100
#define PAYLOAD_MAX 100
#define STRING_MAX 100
#define NAME_LENGTH 100

enum NetNodeType { /* Types of network nodes */
	HOST,
	SWITCH
};

enum NetLinkType { /* Types of linkls */
	PIPE,
	SOCKET
};

struct net_node { /* Network node, e.g., host or switch */
	enum NetNodeType type;
	int id;
	struct net_node *next;
};

struct net_port { /* port to communicate with another node */
	enum NetLinkType type;
	int pipe_host_id;
	int pipe_send_fd;
	int pipe_recv_fd;
	struct net_port *next;
};

/* Packet sent between nodes  */

struct packet { /* struct for a packet */
	char src;
	char dst;
	char type;
	int length;
	char payload[PAYLOAD_MAX];
	int RootID;
	int RootDist;
	char SenderType;
	char SenderChild;
};

/* Types of packets */
#define PKT_PING_REQ		0
#define PKT_PING_REPLY		1
#define PKT_FILE_UPLOAD_START	2
#define PKT_FILE_UPLOAD_END	3
#define PKT_FILE_UPLOAD_CONTINUE	4
#define PKT_FILE_DOWNLOAD_REQ	5
#define PKT_TREE_DISCOVERY 6