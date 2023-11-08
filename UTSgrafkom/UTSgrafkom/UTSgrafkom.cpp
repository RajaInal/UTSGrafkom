#include <GL/glut.h>
#include <math.h>
//Muhammad Raja Inal Lubis 211401134
//pemandangan yang digunakan dalam program [rumah-rumah, trotoar, jalan, dan garis jalan]
//membuat bagian rumah
void homes()
{
    glBegin(GL_QUADS); //menggambar objek empat sisi dari 4 vertex
    glColor3ub(100, 100, 100); //mengatur warna objek 0-255
    glVertex2f(-320, 100);
    glVertex2f(-180, 100);
    glVertex2f(-180, -40);
    glVertex2f(-320, -40);

    glColor3ub(255, 0, 0);
    glVertex2f(-180, 65);
    glVertex2f(-80, 65);
    glVertex2f(-80, -40);
    glVertex2f(-180, -40);

    glColor3ub(255, 255, 0);
    glVertex2f(-80, 105);
    glVertex2f(0, 105);
    glVertex2f(0, -40);
    glVertex2f(-80, -40);

    glColor3ub(139, 69, 19);
    glVertex2f(0, 85);
    glVertex2f(210, 85);
    glVertex2f(210, -40);
    glVertex2f(0, -40);

    glColor3ub(128, 0, 128);
    glVertex2f(210, 150);
    glVertex2f(320, 150);
    glVertex2f(320, -40);
    glVertex2f(210, -40);
    glEnd();
}
//membuat bagian rumah

//membuat bagian trotoar
void trotoar()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 0);
    glVertex2f(-320, -40);
    glVertex2f(320, -40);
    glVertex2f(320, -140);
    glVertex2f(-320, -140);
    glEnd();
}
//membuat bagian trotoar

//membuat bagian jalan
void road()
{
    glBegin(GL_QUADS);
    glColor3ub(100, 100, 100);
    glVertex2f(-320, -140);
    glVertex2f(320, -140);
    glVertex2f(320, -240);
    glVertex2f(-320, -240);
    glEnd();
}
//membuat bagian jalan

//membuat bagian garis jalan
void roadLine()
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-320, -190);
    glVertex2f(320, -190);
    glVertex2f(320, -195);
    glVertex2f(-320, -195);
    glEnd();
}
//membuat bagian garis jalan
//end of view

//membuat objek kereta api kecil yang digerakkan dengan klik mouse
float STX = -30.0;
float STY = -100.0;
float STSize = 30.0;

void smallTrain()
{
    //bagian depan kereta
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(STX, STY);
    glVertex2f(STX + STSize, STY);
    glColor3f(0.5, 0, 1); //mengatur warna objek 0-1 [float]
    glVertex2f(STX + STSize, STY + STSize);
    glVertex2f(STX, STY + STSize);
    //bagian depan kereta

    //bagian belakang kereta
    glColor3ub(0, 0, 255);
    glVertex2f(STX + 30, STY);
    glVertex2f(STX + 60, STY);
    glColor3f(0, 1, 1);
    glVertex2f(STX + 60, STY + 30);
    glVertex2f(STX + 30, STY + 30);
    //bagian belakang kereta
    glEnd();
}

//pergerakan objek ke kiri dan ke kanan dengan mouse click
void mouseFunc(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //trigger: mouse kiri dan posisi ditekan
        STX = x - 320; //terhadap sumbu X
        //squareY = 240 - y;
        glutPostRedisplay(); //menandai window saat ini untuk ditampilkan ulang
    }
}
//end of klik mouse

//membuat objek balon udara yang digerakkan dengan spesial key
float ABX = -125.0;
float ABY = 190.0;
float ABRadius = 20.0;

void airBalloon()
{
    //bagian tali balon udara
    glBegin(GL_QUADS);
    glColor3ub(60, 110, 222);
    glVertex2f(ABX - 1, ABY - 40);
    glVertex2f(ABX + 1, ABY - 40);
    glVertex2f(ABX + 1, ABY);
    glVertex2f(ABX - 1, ABY);
    //bagian tali balon udara
    glEnd();

    //bagian balon udara
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(123, 65, 21);
    glVertex2f(ABX, ABY);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265 / 180.0;
        glVertex2f(ABX + ABRadius * cos(angle), ABY + ABRadius * sin(angle));
    }
    //bagian balon udara
    glEnd();

    //bagian tempat penumpang
    glBegin(GL_QUADS);
    glColor3ub(60, 110, 0);
    glVertex2f(ABX - 10, ABY - 40);
    glVertex2f(ABX + 10, ABY - 40);
    glVertex2f(ABX + 10, ABY - 50);
    glVertex2f(ABX - 10, ABY - 50);
    //bagian tempat penumpang
    glEnd();
}

void handleSpecialKey(int key, int x, int y)
{
    // Membuat pergerakan lingkaran menggunakan tombol panah
    const float stepSize = 10.0f;
    switch (key) {
    case GLUT_KEY_LEFT: //panah kiri
        ABX -= stepSize;
        break;
    case GLUT_KEY_RIGHT: //panah kanan
        ABX += stepSize;
        break;
    case GLUT_KEY_UP: //panah atas
        ABY += stepSize;
        break;
    case GLUT_KEY_DOWN: //panah bawah
        ABY -= stepSize;
        break;
    }
    glutPostRedisplay();
}
//end of spesial key

//membuat objek mobil yang digerakkan dengan keyboard [WASD]
float BCX = 85.0;
float BCY = -155.0;
float BCWidth = 40.0;
float BCHeight = 20.0;

void bigCar()
{
    //bagian atas mobil
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255);
    glVertex2f(BCX, BCY);
    glVertex2f(BCX + BCWidth, BCY);
    glVertex2f(BCX + BCWidth, BCY - BCHeight);
    glVertex2f(BCX, BCY - BCHeight);
    //bagian atas mobil

    //bagian roda mobil
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(BCX, BCY);
    glVertex2f(BCX + 10, BCY);
    glVertex2f(BCX + 10, BCY + 10);
    glVertex2f(BCX, BCY + 10);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(BCX + 30, BCY);
    glVertex2f(BCX + 40, BCY);
    glVertex2f(BCX + 40, BCY + 10);
    glVertex2f(BCX + 30, BCY + 10);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(BCX, BCY - 20);
    glVertex2f(BCX + 10, BCY - 20);
    glVertex2f(BCX + 10, BCY - 30);
    glVertex2f(BCX, BCY - 30);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(BCX + 30, BCY - 20);
    glVertex2f(BCX + 40, BCY - 20);
    glVertex2f(BCX + 40, BCY - 30);
    glVertex2f(BCX + 30, BCY - 30);
    //bagian roda mobil
    glEnd();
}

void handleKeyPress(unsigned char key, int x, int y)
{
    // Membuat pergerakan menggunakan tombol WASD
    const float stepSize = 10.0f;
    if (key == 'w') {
        BCY += stepSize; //atas, + sumbu y
    }
    else if (key == 's') {
        BCY -= stepSize; //bawah, - sumbu y
    }
    else if (key == 'a') {
        BCX -= stepSize; //kiri, - sumbu x
    }
    else if (key == 'd') {
        BCX += stepSize; //kanan, + sumbu x
    }
    glutPostRedisplay();
}
//end of keyboard

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    homes();
    trotoar();
    road();
    roadLine();
    bigCar();
    smallTrain();
    airBalloon();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("City View");
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    gluOrtho2D(-320, 320, -240, 240);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyPress);
    glutSpecialFunc(handleSpecialKey);
    glutMouseFunc(mouseFunc);
    glutMainLoop();
}