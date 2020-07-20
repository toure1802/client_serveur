int main()
{
	// creation de l'espace pour le mesage provenant du serveur
	char buffer[50] = {0};
	struct sokaddr_in servaddr = {0};

	struct sockaddr_in servaddr = {0};
	//creation du socket serveur
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	//si la connexion echoue elle va affiche un message d'erreur
	if(sockfd == -1)
	{
		perror("faild to create socket");
		exit(EXIT_FAILURE);
	}
	// configuration du port 
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(12345);
	servaddr.sin_addr.s_addr = INADDR_ANY;
@@ -30,7 +33,7 @@ int main()
		exit(EXIT_FAILURE);
	}
	socklen_t len = 0;

	// reception du message de client
	int n = recvfrom(sockfd, (char *)buffer, 50, MSG_WAITALL, 0, &len);
	buffer[n] = '\n';
	printf("%s", buffer);
