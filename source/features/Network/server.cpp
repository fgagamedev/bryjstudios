#include<iostream>
#include<SDL/SDL.h>
#include<SDL/SDL_net.h>
#include<cstring>
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

using namespace std;

TCPsocket Sclient;


TCPsocket server;
int criar_servidor(){

	IPaddress ip;
	if(SDLNet_ResolveHost(&ip,NULL,1234) < 0){
        return 1;
    }

        server = SDLNet_TCP_Open(&ip);
        if(!server){
            return 1;
        }

    while(1){
    //start = SDL_GetTicks();
    //
        Sclient = SDLNet_TCP_Accept(server);

        if(Sclient){
            /*SDL_Delay(1);
            char muah[100];
            cin.getline(muah,100);
            SDLNet_TCP_Send(Sclient,muah,strlen(muah)+1);
            cout<<"Mandei a msg: "<<muah<<endl;*/
            return 1;
        }
        if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
            SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
        }
    }

}

    /*
	char text[100];

	while(1){
		client = SDLNet_TCP_Accept(server);
		if(client){

			while(1){
				//aqui você pode comunicar com o cliente
				//SDLNet_TCP_Send (client,text,strlen(text)+1);
				cout<<"Sua vez de digitar"<<endl;
				cin.getline(text,100);
				SDLNet_TCP_Send(client,&text,100);
				cout<<"O cliente vai digitar..."<<endl;
				SDLNet_TCP_Recv(client,text,100);
				cout<<"O cliente diz: "<<text<<endl;
					if(strcmp(text,"sair") ==0){
						SDLNet_TCP_Close(client);
						SDLNet_TCP_Close(server);
						SDLNet_Quit();
						SDL_Quit();
						return 0;
					}

			}
		}
	}
	SDLNet_TCP_Close(server); // precisa fechar porque senão,
				 // não dá pra usar a mesma porta denovo

	SDLNet_Quit();
	SDL_Quit();
}*/
