class Robot {
    int WIDTH, HEIGHT;
    int currX, currY;
    int dir;
    int REVOLUTION;
    // 0 -> north, 1 -> east, 2 -> west, 3 -> south
public:
    Robot(int width, int height) : WIDTH(width), HEIGHT(height) {
        currX = currY = 0;
        dir = 1;
        REVOLUTION = 2 * WIDTH + 2 * HEIGHT - 4;
    }
    
    void step(int num) {
        if (currX == 0 && currY == 0 && REVOLUTION <= num) {
            dir = 3;
        }
        num %= REVOLUTION;
        
        while (num > 0) {
            if (dir == 1) {
                if (num >= (WIDTH - currX - 1)) {
                    if ((WIDTH - currX - 1) == 0) {
                        dir = 0;
                    } else {
                        num -= (WIDTH - currX - 1);
                        currX = WIDTH - 1;
                        currY = 0;
                    }
                } else {
                    currX += num;
                    num = 0;
                }
            } else if (dir == 0) {
                if (num >= (HEIGHT - currY - 1)) {
                    if ((HEIGHT - currY - 1) == 0) {
                        dir = 2;
                    } else {
                        num -= (HEIGHT - currY - 1);
                        currX = WIDTH - 1;
                        currY = HEIGHT - 1;
                    }
                } else {
                    currY += num;
                    num = 0;
                }
            } else if (dir == 2) {
                if (num >= currX) {
                    if (currX == 0) {
                        dir = 3;
                    } else {
                        num -= currX;
                        currX = 0;
                        currY = HEIGHT - 1;
                    }
                } else {
                    currX -= num;
                    num = 0;
                }
            } else {
                if (num >= currY) {
                    if (currY == 0) {
                        dir = 1;
                    } else {
                        num -= currY;
                        currX = 0;
                        currY = 0;
                    }
                } else {
                    currY -= num;
                    num = 0;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {currX, currY};
    }
    
    string getDir() {
        if (dir == 0) {
            return "North";
        } else if (dir == 1) {
            return "East";
        } else if (dir == 2) {
            return "West";
        } else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */