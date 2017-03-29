/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

int gcd(int a, int b) {
    if(b == 0){
        cout << "gcd("<< a << ","<< b << ") =" << a <<endl;
        return a;
    }else{
        cout << "gcd("<< a << ","<< b << ") =" << "gcd(" << b << "," << a%b << ")" << endl;
        return gcd(b,a%b);
    }

    cout << "[recursion gcd called]" << endl;
    return 0;
}



void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    if (order>0){
        //w.setLocation(leftX,leftY);
        w.drawLine(leftX,leftY,leftX+size,leftY);
        w.drawPolarLine(leftX+size,leftY,size,240);
        w.drawPolarLine(leftX+(size/2),(leftY+(sqrt(3)/2)*size),size,120);
        serpinskii(w,leftX,leftY,size/2,order-1);
        serpinskii(w,leftX+(size/2),leftY,size/2,order-1);
        serpinskii(w,leftX+(size/4),leftY+(sqrt(3)/4)*size,size/2,order-1);
    }
    //cout << "[recursion serpinskii called]" << endl;
}

int count;
int floodFill(GBufferedImage& image, int x, int y, int newColor) {

    static int oldColor = image.getRGB(x,y);
    int colorNow = image.getRGB(x,y);

    if (colorNow == newColor){
        return 0;
    }

    if(image.inBounds(x,y)){
        if(colorNow == oldColor){
                image.setRGB(x,y,newColor);
                floodFill(image, x-1, y, newColor);
                floodFill(image, x+1, y, newColor);
                floodFill(image, x, y-1, newColor);
                floodFill(image, x, y+1, newColor);
                count++;
                return count;
            }else{
                    return 1;
                }
        }else{
            return 1;
        }
    cout << "[recursion flood fill called]" << endl;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    // your code here
    cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return "";
}
