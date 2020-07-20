int main()
{
	char * hello = "hello from client";
	// configuration d'un message pour le serveur
	char * toto = "salut je me suis connect client";
	struct sockaddr_in servaddr = {0};

	// confuguration du soket clent
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	// si la connexion echoue elle va affiche un message d'erreur
	if(sockfd == -1)
	{
		perror("failed to creat socket");
		exit(EXIT_FAILURE);
	}

	//configuration du port 
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(12345);
	servaddr.sin_addr.s_addr = INADDR_ANY;

	int len = sendto(sockfd, (const char *)hello, strlen(hello), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
	// envoie du message au serveur 
	int len = sendto(sockfd, (const char *)toto, strlen(toto), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
	//si l'envoie du message rate elle va envoie un message d'erreur
	if(len == -1)
	{
		perror("failed to send");
	}
	// fermeture du programme apres connexion
	close(sockfd);

	return 0;
