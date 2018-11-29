#ifndef TORTUGA_H
#define TORTUGA_H
#define BASIC_X_POSITION 500
#define BASIC_Y_POSITION 500
#include <iostream>



using namespace std;


class Tortuga{
    public:
        Tortuga(float xPos = BASIC_X_POSITION, float yPos = BASIC_Y_POSITION) {
            setXPosition(xPos);
            setYPosition(yPos);
            setOrientation(90);

        }
        ~Tortuga() {}
        void setXPosition(float pX){
            this->xPosition = pX;
        }
        void setYPosition(float pY){
            this->yPosition = pY;
        }
        void setOrientation(float pOr){
            this->orientation = pOr;
        }
        float getXPosition(){
            return xPosition;
        }
        float getYPosition(){
            return yPosition;
        }
        float getOrientation(){
            return orientation;
        }

        void getWholePosition(){
            cout << yPosition <<"\t" << xPosition << endl;
        }

        void moveUp(){
            yPosition = yPosition - 50;
        }
        void moveDown(){
            yPosition = yPosition + 50;
        }
        void moveRight(){
            xPosition = xPosition - 50;
        }
         void moveLeft(){
            xPosition = xPosition + 50;
        }
        /*const float PI  = 3.1416;
        const float GradosToRad = */

    protected:

    private:
        float xPosition;
        float yPosition;
        float orientation;

};

#endif // TORTUGA_H
