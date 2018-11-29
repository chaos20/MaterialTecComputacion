#ifndef TORTUGA_H
#define TORTUGA_H
#include <SDL.h>
#include <cmath>
#include <stdexcept>
#include "DLinkedList.h"
#define DEFAULT_X 300
#define DEFAULT_Y 240
#define DEFAULT_ANGLE 0

using namespace std;

class Tortuga{
private:
    double x;
    double y;
    double angle;

public:

    Tortuga(){
        angle = DEFAULT_ANGLE;
        x = DEFAULT_X;
        y = DEFAULT_Y;
    }

    ~Tortuga(){
    }

    DLinkedList<string>* curvaDeDragon(int iterations){
        string curve = "";
        DLinkedList<string> *curvaDeDragon = new DLinkedList<string>();
        for(int i = 0; i < iterations; i++){
            curve = "90";
            if(i == 0)
                curvaDeDragon->insert(curve);
            else{
                curvaDeDragon->goToStart();
                do{
                    if(curvaDeDragon->getPos() % 2 == 0){
                        curvaDeDragon->insert(curve);
                        if(curve == "90")
                            curve = "-90";
                        else
                            curve = "90";
                    }
                    curvaDeDragon->next();
                }while(curvaDeDragon->atEnd() == false);
                curvaDeDragon->append(curve);
            }
        }
        if(iterations > 0){
            curvaDeDragon->goToStart();
            do{
                if(curvaDeDragon->getPos() % 2 == 0){
                    curvaDeDragon->insert("A");
                }
                curvaDeDragon->next();
            } while(curvaDeDragon->atEnd() == false);
            curvaDeDragon->append("A");
        }
        return curvaDeDragon;
    }

    DLinkedList<string>* flechaDeSierpinski(int iterations){
        string curve = "30";
        DLinkedList<string> *flechaDeSierpinski = new DLinkedList<string>();
        for(int i = 0; i < iterations; i++){
            if(i == 0){
                flechaDeSierpinski->insert(curve);
                flechaDeSierpinski->insert(curve);
            }else{
                flechaDeSierpinski->goToStart();
                if(curve == "30")
                    curve = "-30";
                else
                    curve = "30";
                do{
                    if(flechaDeSierpinski->getPos() % 3 == 0){
                        flechaDeSierpinski->insert(curve);
                        flechaDeSierpinski->insert(curve);
                        if(curve == "30")
                            curve = "-30";
                        else
                            curve = "30";
                    }
                    flechaDeSierpinski->next();
                }while(flechaDeSierpinski->atEnd() == false);
                flechaDeSierpinski->append(curve);
                flechaDeSierpinski->append(curve);
            }
        }
        if(iterations > 0){
            flechaDeSierpinski->goToStart();
            do{
                if(flechaDeSierpinski->getPos() % 2 == 0){
                    flechaDeSierpinski->insert("A");
                }
                flechaDeSierpinski->next();
            } while(flechaDeSierpinski->atEnd() == false);
            flechaDeSierpinski->append("A");
        }
        return flechaDeSierpinski;
    }

    DLinkedList<string>* curvaDeLevy(int iterations){
        DLinkedList<string> *curvaDeLevy = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                curvaDeLevy->insert("A");
            else{
                curvaDeLevy->goToStart();
                do{
                    if(curvaDeLevy->getElement() == "A"){
                        curvaDeLevy->remove();
                        curvaDeLevy->insert("45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("A");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("-45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("-45");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("A");
                        curvaDeLevy->next();
                        curvaDeLevy->insert("45");
                    }
                    curvaDeLevy->next();
                }while(curvaDeLevy->atEnd() == false);
            }
        }
        return curvaDeLevy;
    }

    DLinkedList<string>* arbolBinario(int iterations){
        DLinkedList<string> *arbolBinario = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                arbolBinario->insert("H");
            else{
                arbolBinario->goToStart();
                do{
                    if(arbolBinario->getElement() == "H"){
                        arbolBinario->remove();
                        arbolBinario->insert("R");
                        arbolBinario->next();
                        arbolBinario->insert("(");
                        arbolBinario->next();
                        arbolBinario->insert("H");
                        arbolBinario->next();
                        arbolBinario->insert(")");
                        arbolBinario->next();
                        arbolBinario->insert("H");
                    }else if(arbolBinario->getElement() == "R"){
                        arbolBinario->remove();
                        arbolBinario->insert("R");
                        arbolBinario->next();
                        arbolBinario->insert("R");
                    }
                    arbolBinario->next();
                }while(arbolBinario->atEnd() == false);
            }
        }
        return arbolBinario;
    }

    DLinkedList<string>* planta(int iterations){
        DLinkedList<string> *planta = new DLinkedList<string>;
        for(int i = 0; i < iterations; i++){
            if(i == 0)
                planta->insert("X");
            else{
                planta->goToStart();
                do{
                    if(planta->getElement() == "X"){
                        planta->remove();
                        planta->insert("A");
                        planta->next();
                        planta->insert("D");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("I");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("I");
                        planta->next();
                        planta->insert("A");
                        planta->next();
                        planta->insert("(");
                        planta->next();
                        planta->insert("I");
                        planta->next();
                        planta->insert("A");
                        planta->next();
                        planta->insert("X");
                        planta->next();
                        planta->insert(")");
                        planta->next();
                        planta->insert("D");
                        planta->next();
                        planta->insert("X");
                    }else if(planta->getElement() == "A"){
                        planta->remove();
                        planta->insert("A");
                        planta->next();
                        planta->insert("A");
                    }
                    planta->next();
                }while(planta->atEnd() == false);
            }
        }
        return planta;
    }

    void draw(DLinkedList<string> *fractal){
        bool finish = false;
        int newY;
        int newX;
        setAngle(0);
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
            SDL_Window* window = NULL;
            SDL_Renderer* renderer = NULL;

            if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
                SDL_bool done = SDL_FALSE;

                while (!done) {
                    SDL_Event event;

                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderClear(renderer);

                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                    if(!finish){
                        for(fractal->goToStart(); !fractal->atEnd(); fractal->next()){
                            if(fractal->getElement() == "A"){
                                double angleRadians = (angle * M_PI) / 180;
                                newX = (sin(angleRadians) * 40) + x;
                                newY = (cos(angleRadians) * 40) + y;
                                SDL_RenderDrawLine(renderer, x, y, newX, newY);
                                SDL_RenderPresent(renderer);
                                x = newX;
                                y = newY;
                            }else if(fractal->getElement() == "90"){
                                if(angle == 270){
                                    angle = 0;
                                }else{
                                    angle = angle + 90;
                                }
                            }else if(fractal->getElement() == "-90"){
                                if(angle == 0){
                                    angle = 270;
                                }else{
                                    angle = angle - 90;
                                }
                            }else if(fractal->getElement() == "30"){
                                if(angle == 330){
                                    angle = 0;
                                }else{
                                    angle = angle + 30;
                                }
                            }else if(fractal->getElement() == "-30"){
                                if(angle == 0){
                                    angle = 330;
                                }else{
                                    angle = angle - 30;
                                }
                            }else if(fractal->getElement() == "45"){
                                if(angle == 315){
                                    angle = 0;
                                }else{
                                    angle = angle + 45;
                                }
                            }else if(fractal->getElement() == "-45"){
                                if(angle == 0){
                                    angle = 315;
                                }else{
                                    angle = angle - 45;
                                }
                            }

                        }
                        finish = true;
                    }
                    /*SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
                    SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
                    SDL_RenderDrawLine(renderer, 340, 240, 320, 200);*/
                    SDL_RenderPresent(renderer);

                    while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                            done = SDL_TRUE;
                        }
                    }
                }
            }

            if (renderer) {
                SDL_DestroyRenderer(renderer);
            }
            if (window) {
                SDL_DestroyWindow(window);
            }
        }
        SDL_Quit();
    }

    void setAngle(double pAngle){
        angle = pAngle;
    }
};

#endif // TORTUGA_H
