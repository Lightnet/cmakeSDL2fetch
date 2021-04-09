#include <stdio.h>
#include <string.h>
#include <SDL.h>
#undef main

int main(int argc, char** argv)
{
  printf("Initialize the SDL2...\n");
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("Failed to initialize the SDL2 library\n");
    printf("SDL2 Error: ", SDL_GetError(), "\n");
    return -1;
  }

	SDL_Window* window = SDL_CreateWindow("SDL with Premake", 150, 150, 800, 600, SDL_WINDOW_SHOWN);

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  //The surface contained by the window
  SDL_Surface* screenSurface = NULL;

  if(!window_surface){
    printf("Failed to get the surface from the window\n");
    return -1;
  }
  printf("init window render loop \n");
  bool keep_window_open = true;
  while(keep_window_open)
  {
    SDL_Event e;
    while(SDL_PollEvent(&e) > 0)
    {
      switch(e.type)
      {
        case SDL_QUIT:
          keep_window_open = false;
          break;
      }
      //Get window surface
      screenSurface = SDL_GetWindowSurface( window );

      //Fill the surface white
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
      //SDL_FillRect( window_surface, NULL, SDL_MapRGB( window_surface->format, 0xFF, 0xFF, 0xFF ) );

      //SDL_BlitSurface(image, NULL, window_surface, NULL);
      SDL_UpdateWindowSurface(window);
      //printf("render \n");

      //Wait two seconds
      //SDL_Delay( 2000 );
    }
  }

	SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}