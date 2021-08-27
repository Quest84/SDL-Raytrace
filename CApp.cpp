#include "CApp.h"

// Constructor por defecto
CApp::CApp()
{
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool CApp::OnInit()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        return false;
    }

    pWindow = SDL_CreateWindow( "Aplicación", 
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN );
    
    if( pWindow != NULL )
    {
        pRenderer = SDL_CreateRenderer( pWindow, -1, 0 );
    }
    else
    {
        return false;
    }

    return true;
}

int CApp::OnExecute()
{
    SDL_Event event;

    if( !OnInit() )
    {
        return -1;
    }
    
    while( isRunning )
    {
        while( SDL_PollEvent(&event) != 0 )
        {
            OnEvent( &event );
        }
     
        OnLoop();
        OnRender();
    }

    return 0;
}

void CApp::OnEvent( SDL_Event *event )
{
    if( event->type == SDL_QUIT )
    {
        isRunning = false;
    }
    switch(event->type)
    {
        case SDL_KEYDOWN:
            switch( event->key.keysym.sym )
            {
                case SDLK_q:
                    printf( "Bye!" );
                    isRunning = false;
                    break;
            }
    }
}

void CApp::OnLoop()
{

}

void CApp::OnRender()
{
    // Establece el fondo de color blanco
    SDL_SetRenderDrawColor( pRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( pRenderer );

    // Muestra el resultado
    SDL_RenderPresent( pRenderer );
}

void CApp::OnExit()
{
    // Termina SDL2 y deinicializa cosas
    SDL_DestroyRenderer( pRenderer );
    SDL_DestroyWindow( pWindow );
    pWindow = NULL;
    pRenderer = NULL;

    SDL_Quit();
}
