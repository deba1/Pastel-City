#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <windows.h>

bool _fullscreen = false;
bool _night = false;
bool _rainy = false;
float m_x = 0;
float m_y = 0;

float _speed = 0.0025f;
float _sun_y = 0.5f;

float _plane_x = -0.25f;

bool _flap = true;
float _bird_x = 0.0;
float _bird_y = 0.0;
float _bird_a = 0.0;

float _cloud_x = 0.0;
float _truck_x = 0.0;

int _rain_drop = 0;

float _car_1_x = 0.00f;
float _speed_car_1 = 0.0025f;

float _car_2_x = 0.00f;
float _speed_car_2 = 0.0025f;

float _move_car_3 = 0.00f;
float _speed_car_3 = 0.0025f;

float _train_x = 0.00f;
float _speed_train = 0.0025f;

float _boat_2_x = 0.00f;
float _speed_ship = 0.0025f;

float _cloud_2_x = 0.00f;
float _boat_1_x = 0.00f;

float _fish_x = 0.00f;
float _man_x = 0.0f;

float _speed_sun = 0.0025f;

void *currentfont;


void update_car_1(int value) {
    _car_1_x += _speed;
    if(_car_1_x-1.3 > 1.0)
    {
        _car_1_x = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_car_2(int value) {
    _car_2_x -= _speed*0.7;
    if(_car_2_x+1.3 < -1.0)
    {
        _car_2_x = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_2, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_car_3(int value) {
    if(_speed_car_3>1 || _speed_car_3<0)
    {
        _speed_car_3 = 0.0f;
    }
    _move_car_3 -= _speed_car_3;
    if(_move_car_3+1.3 < -1.0)
    {
        _move_car_3 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_3, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_train(int value) {
    _train_x -= _speed*1.2;
    if(_train_x+1.3 < -1.0)
    {
        _train_x = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_train, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_ship(int value) {
    _boat_2_x -= _speed;
    if(_boat_2_x +1.3 < -1.0)
    {
        _boat_2_x = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_ship, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_sun(int value){
    _sun_y -= _speed;
    if(_sun_y+1.0 < -1.0)
    {
        _sun_y = 1.3;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_sun, 0);
}

void update_truck(int value){
    _truck_x += _speed*0.8;
    if(_truck_x-1.0 > 1.0)
    {
        _truck_x = -1.3;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_truck, 0);
}

void update_cloud_1(int value) {
    _cloud_x += _speed*3.0;
    if(_cloud_x-1.3 > 1.0)
    {
        _cloud_x = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_cloud_2(int value){
    _cloud_2_x -= _speed*0.7;
    if(_cloud_2_x+1.3 < -1.0)
    {
        _cloud_2_x = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_2, 0);
}

void update_boat(int value) {
    _boat_1_x+=_speed*.5;
    if(_boat_1_x-1.3 > 1.0)
    {
        _boat_1_x = -1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_boat, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_fish(int value){
    _fish_x += _speed*0.65;
    if(_fish_x-2.0 > 1.0)
    {
        _fish_x = -3.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_fish, 0);
}

void update_man(int value){
    _man_x += _speed;
    if(_man_x-0.5 > 1.0)
    {
        _man_x = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(70, update_man, 0);
}

void update_plane(int value){
    _plane_x += _speed;
    if(_plane_x-1.3 > 1.0)
    {
        _plane_x = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_plane, 0);
}

void update_bird(int value){
    _bird_x -= _speed;
    if (value%20==0){
        _bird_a++;
        _bird_y = sin(_bird_a)*0.05-0.1;
    }

    if(_bird_x+1.3 < -1.0)
    {
        _bird_x = 1.0;
    }
    if (value%10==0)
        _flap = _flap ? false : true;
	glutPostRedisplay(); //Notify GLUT that the display has changed
    value++;
	glutTimerFunc(20, update_bird, value);
}

void update_rain(int value){
    _rain_drop = _rain_drop==0 ? 1 : (_rain_drop==1 ? 2 : 0);
    glutPostRedisplay();
    glutTimerFunc(250, update_rain, 0);
}

void updateAll(){
    update_car_1(0);
    update_car_2(0);
    update_car_3(0);
    update_train(0);
    update_ship(0);
    update_sun(0);
    update_plane(0);
    update_bird(0);
    update_fish(0);
    update_man(0);
    update_truck(0);
}

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          _speed+= 0.0025f;

          break;
      case GLUT_KEY_DOWN:
          if (_speed<=0)
            _speed = 0;
          else
            _speed-= 0.0025f;
          break;
      case GLUT_KEY_HOME:
        exit(0);
        break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
      case 'f':
        if (_fullscreen)
        {
            _fullscreen = false;
            glutReshapeWindow(1366, 768);
            glutPositionWindow(50, 50);
        }
        else if (!_fullscreen)
        {
            _fullscreen = true;
            glutFullScreen();
        }
        break;
      case 'r':
        _rainy = _rainy ? false : true;
        update_rain(0);
        break;
    }
}

void mouse(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Pause/resume
        float px = 2*(x/1366.0)-1.0;
        float py = -2*y/768.0+1.0;
        m_x = px;
        m_y = py;
        printf("glVertex2f(%.3f, %.3f);\n", px, py);
   }
}

void setFont(void *font){
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string){
	char *ct;
	glRasterPos3f(x,y,z);

	for(ct=string;*ct!='\0';ct++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*ct);
	}
	setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
}

void truck(){
    glPushMatrix();
    glTranslatef(_truck_x, 0.0,0.0);
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.174, -0.234);
    glVertex2f(0.148, -0.234);
    glVertex2f(0.148, -0.190);
    glVertex2f(-0.174, -0.190);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.148, -0.234);
    glVertex2f(0.148, -0.125);
    glVertex2f(0.120, -0.089);
    glVertex2f(0.061, -0.089);
    glVertex2f(0.061, -0.232);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if (_night)
        glColor3f(1.0, 1.0, 0.1);
    else
        glColor3f(0.0, 0.0, 0.0);
    glTranslatef(_truck_x, 0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.081, -0.120);
    glVertex2f(0.081, -0.156);
    glVertex2f(0.119, -0.156);
    glVertex2f(0.116, -0.130);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_truck_x, 0.0,0.0);
    glTranslatef(-0.120, -0.245, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_truck_x, 0.0,0.0);
    glTranslatef(-0.120, -0.245, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_truck_x, 0.0,0.0);
    glTranslatef(0.094, -0.234, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_truck_x, 0.0,0.0);
    glTranslatef(0.094, -0.234, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
}

void lorry(){

}

void sky(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    if(_sun_y<=1.20f && _sun_y>=0.90f){
        glColor3f(0.529, 0.808, 0.922);
        _night = false;
    }
    else if(_sun_y<0.90f && _sun_y>=0.55f)
        glColor3f(0.000, 0.749, 1.000);
    else if(_sun_y<0.55f && _sun_y>=0.35f)
        glColor3f(0.000, 0.749, 1.000);
    else if(_sun_y<0.35f && _sun_y>=0.25f)
        glColor3f(0.529, 0.808, 0.980);
    else if(_sun_y<0.25f && _sun_y>=0.10f)
        glColor3f(0.529, 0.808, 0.980);
    else if(_sun_y<0.10f && _sun_y>=-0.10f)
        glColor3f(0.529, 0.808, 0.980);
    else {
        _night = true;
        glColor3f(0.412, 0.412, 0.412);
    }

    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0, -0.05);
    glVertex2f(-1.0, -0.05);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0f, _sun_y, 0.0f);
    glTranslatef(0.0,1.25,0);
    glScalef(0.6,1,1);
    glColor3f(0.902, 0.902, 0.980);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.085;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}

void stars(){
    glPushMatrix();
    glPointSize(5.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.95,0.95);
    glVertex2f(-0.826, 0.737);
    glVertex2f(-0.574, 0.875);
    glVertex2f(-0.369, 0.500);
    glVertex2f(-0.028, 0.568);
    glVertex2f(0.225, 0.758);
    glVertex2f(0.388, 0.495);
    glVertex2f(0.574, 0.628);
    glVertex2f(0.786, 0.385);
    glVertex2f(0.767, 0.859);
    glVertex2f(0.921, 0.583);
    glEnd();
    glPopMatrix();
}

void plane(){
    glPushMatrix();
    glTranslatef(_plane_x, 0.05,0.0);
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.763, 0.836);
    glVertex2f(-0.798, 0.888);
    glVertex2f(-0.761, 0.891);
    glVertex2f(-0.710, 0.836);
    glEnd();
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.908, 0.84);
    glVertex2f(-0.886, 0.771);
    glVertex2f(-0.6, 0.771);
    glVertex2f(-0.605, 0.810);
    glVertex2f(-0.638, 0.845);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.909, 0.836);
    glVertex2f(-0.928, 0.901);
    glVertex2f(-0.889, 0.909);
    glVertex2f(-0.864, 0.839);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.757, 0.799);
    glVertex2f(-0.821, 0.672);
    glVertex2f(-0.776, 0.669);
    glVertex2f(-0.688, 0.802);
    glEnd();
    if (_night)
        glColor3f(0.9,0.9,0.0);
    else
        glColor3f(0.5,0.9,1.0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-0.823, 0.818);
    glVertex2f(-0.801, 0.818);
    glVertex2f(-0.668, 0.818);
    glVertex2f(-0.646, 0.818);
    glVertex2f(-0.766, 0.818);
    glVertex2f(-0.742, 0.818);
    glVertex2f(-0.714, 0.818);
    glVertex2f(-0.681, 0.818);
    glVertex2f(-0.637, 0.818);
    glVertex2f(-0.616, 0.818);
    glVertex2f(-0.578, 0.818);
    glEnd();

    glPopMatrix();
}

void birds(){
    glPushMatrix();
    glTranslatef(_bird_x, _bird_y,0.0);
    glTranslatef(0.7,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    if (_flap)
        glVertex2f(-0.349, 0.895);
    else
        glVertex2f(-0.349, 0.875);
    glVertex2f(-0.335, 0.865);
    glVertex2f(-0.335, 0.865);
    if (_flap)
        glVertex2f(-0.32, 0.895);
    else
        glVertex2f(-0.32, 0.875);


    if (_flap)
        glVertex2f(-0.249, 0.895);
    else
        glVertex2f(-0.249, 0.875);
    glVertex2f(-0.235, 0.865);
    glVertex2f(-0.235, 0.865);
    if (_flap)
        glVertex2f(-0.22, 0.895);
    else
        glVertex2f(-0.22, 0.875);


    if (_flap)
        glVertex2f(-0.300, 0.85);
    else
        glVertex2f(-0.300, 0.83);
    glVertex2f(-0.285, 0.82);
    glVertex2f(-0.285, 0.82);
    if (_flap)
        glVertex2f(-0.27, 0.85);
    else
        glVertex2f(-0.27, 0.83);
    glEnd();

    glPopMatrix();
}

void field(float bottom, float height){
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(1.0, bottom);
    glVertex2f(-1.0, bottom);
    glVertex2f(-1.0, bottom+height);
    glVertex2f(1.0, bottom+height);

    glEnd();
}

void rail_track(){
    //Rail track
    glBegin(GL_QUADS);
    glColor3f(0.439, 0.592, 0.565);
    glVertex2f(-1.0, -0.615);
    glVertex2f(-1.0, -0.6);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -0.615);

    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(-1.0, -0.68);
    glVertex2f(-1.0, -0.665);
    glVertex2f(1.0, -0.665);
    glVertex2f(1.0, -0.68);

    glColor3f(0.184, 0.310, 0.310);
    for(float i = -0.99; i<=1; i =i+0.03){
        glVertex2f(i,-0.615);
        glVertex2f(i+0.015,-0.665);
        glVertex2f(i+0.025, -0.665);
        glVertex2f(i+0.01, -0.615);
    }
    glEnd();
}

void train(){

    glColor3d(0.282, 0.239, 0.545);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);

    glBegin(GL_POLYGON);
        glVertex2f(0.05-0.035, 0.065-0.474);
        glVertex2f(0.30-0.035, 0.065-0.474);
        glVertex2f(0.30-0.035, 0.26-0.474);
        glVertex2f(0.05-0.035, 0.26-0.474);
	glEnd();
    glPopMatrix();

    if (_night)
        glColor3f(1.0, 1.0, 0.1);
    else
        glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.07-0.035, 0.110-0.474);
        glVertex2f(0.28-0.035, 0.110-0.474);
        glVertex2f(0.28-0.035, 0.215-0.474);
        glVertex2f(0.07-0.035, 0.215-0.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.17-0.035, 0.110-0.474);
        glVertex2f(0.18-0.035, 0.110-0.474);
        glVertex2f(0.18-0.035, 0.215-0.474);
        glVertex2f(0.17-0.035, 0.215-0.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.07-0.035, 0.235-0.474);
        glVertex2f(0.28-0.035, 0.235-0.474);
        glVertex2f(0.28-0.035, 0.26-0.474);
        glVertex2f(0.07-0.035, 0.26-0.474);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
        glTranslatef(0.10,0.065-.682,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
        glTranslatef(0.25+0.085,0.065-.682,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glColor3d(0.275, 0.510, 0.706);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.035+0.30, 0.075-0.474);
        glVertex2f(-0.035+0.35, 0.075-0.474);
        glVertex2f(-0.035+0.35, 0.095-0.474);
        glVertex2f(-0.035+0.30, 0.095-0.474);
	glEnd();
    glPopMatrix();

	/////////////////////////
	glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.035+0.35, 0.065-0.474);
        glVertex2f(-0.035+0.60, 0.065-0.474);
        glVertex2f(-0.035+0.60, 0.26-0.474);
        glVertex2f(-0.035+0.35, 0.26-0.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.035+0.37, 0.110-0.474);
        glVertex2f(-0.035+0.58, 0.110-0.474);
        glVertex2f(-0.035+0.58, 0.215-0.474);
        glVertex2f(-0.035+0.37, 0.215-0.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
        glVertex2f(-0.035+0.47, 0.110-0.474);
        glVertex2f(-0.035+0.48, 0.110-0.474);
        glVertex2f(-0.035+0.48, 0.215-0.474);
        glVertex2f(-0.035+0.47, 0.215-0.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.035+0.37, 0.235-0.474);
        glVertex2f(-0.035+0.58, 0.235-0.474);
        glVertex2f(-0.035+0.58, 0.26-0.474);
        glVertex2f(-0.035+0.37, 0.26-0.474);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
        glTranslatef(0.40+0.376,0.065-.682,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
        glTranslatef(0.55,0.065-.682,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glColor3d(0.275, 0.510, 0.706);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-.035+0.60, 0.075-.474);
        glVertex2f(-.035+0.65, 0.075-.474);
        glVertex2f(-.035+0.65, 0.095-.474);
        glVertex2f(-.035+0.60, 0.095-.474);
	glEnd();
    glPopMatrix();

    /////////////////////////
	glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-.035+0.65, 0.065-.474);
        glVertex2f(-.035+0.90, 0.065-.474);
        glVertex2f(-.035+0.90, 0.26-.474);
        glVertex2f(-.035+0.65, 0.26-.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-.035+0.67, 0.110-.474);
        glVertex2f(-.035+0.88, 0.110-.474);
        glVertex2f(-.035+0.88, 0.215-.474);
        glVertex2f(-.035+0.67, 0.215-.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-.035+0.77, 0.110-.474);
        glVertex2f(-.035+0.78, 0.110-.474);
        glVertex2f(-.035+0.78, 0.215-.474);
        glVertex2f(-.035+0.77, 0.215-.474);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
	glScalef(1.5,1.5,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-.035+0.67, 0.235-.474);
        glVertex2f(-.035+0.88, 0.235-.474);
        glVertex2f(-.035+0.88, 0.26-.474);
        glVertex2f(-.035+0.67, 0.26-.474);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
        glTranslatef(0.70+0.302,0.065-.682,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_train_x, 0.0f, 0.0f);
        glTranslatef(0.85+0.373,0.065-.682,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.549, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

        if(_night){
            glColor3f(1.000, 0.973, 0.863);
            glPushMatrix();
            glTranslatef(_train_x, 0.0f, 0.0f);
            glBegin(GL_POLYGON);
                glVertex2f(-0.026+0.05, 0.245-0.602);
                glVertex2f(-0.026+0.05, 0.255-0.602);
                glVertex2f(-0.026+-0.00, 0.26-0.602);
                glVertex2f(-0.026+-0.00, 0.24-0.602);
            glEnd();
            glPopMatrix();
        }
        glutSwapBuffers();
}

void sun() {
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f, _sun_y, 0.0f);
    glScalef(0.6,1,1);
    if(_sun_y<=1.00 && _sun_y>=0.95f)
        glColor3f(1.000, 0.647, 0.000);
    else if(_sun_y<0.95f && _sun_y>=0.85f)
        glColor3f(1.000, 0.843, 0.000);
    else if(_sun_y<0.85 && _sun_y>=0.65)
        glColor3f(1.000, 1.000, 0.000);
    else if(_sun_y<0.65 && _sun_y>=0.45)
        glColor3f(1.000, 0.843, 0.000);
    else if(_sun_y<0.45 && _sun_y>=0.25)
        glColor3f(1.000, 0.647, 0.000);
    else if(_sun_y<0.25 && _sun_y>=0.10)
        glColor3f(1.000, 0.549, 0.000);
    else
        glColor3f(1.000, 0.271, 0.000);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.125;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}

void cloud(float cx){
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_cloud_x, 0.0f, 0.0f);
    glTranslatef(cx,0.82,0);
    glScalef(0.6,1,1);
    if (_rainy)
        glColor3f(0.81, 0.81, 0.81);
    else
        glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.06;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_x, 0.0f, 0.0f);
        glTranslatef(cx+.04,0.87,0);
        glScalef(0.6,1,1);

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_x, 0.0f, 0.0f);
        glTranslatef(cx+0.08,0.91,0);
        glScalef(0.6,1,1);

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_x, 0.0f, 0.0f);
        glTranslatef(cx+0.13,0.88,0);
        glScalef(0.6,1,1);

        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.07;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_x, 0.0f, 0.0f);
        glTranslatef(cx+0.17,0.80,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_x, 0.0f, 0.0f);
        glTranslatef(cx+0.1,0.77,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_x, 0.0f, 0.0f);
        glTranslatef(cx+0.03,0.78,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
}

void cloud_right(){
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
    glTranslatef(0.78,0.70,0);
    glScalef(0.6,1,1);
    if (_rainy)
        glColor3f(0.81, 0.81, 0.81);
    else
        glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.06;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
    glTranslatef(0.74,0.75,0);
    glScalef(0.6,1,1);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.075;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
        glTranslatef(0.70,0.79,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
        glTranslatef(0.65,0.76,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.07;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
        glTranslatef(0.61,0.76,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
        glTranslatef(0.68,0.65,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
        glTranslatef(0.63,0.66,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_cloud_2_x, 0.0f, 0.0f);
        glTranslatef(0.75,0.66,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
}

void building(float x, float h, float r, float g, float b){
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(x, -0.05);
    glVertex2f(x+0.22, -0.05);
    glVertex2f(x+0.22, h-0.05);
    glVertex2f(x, h-0.05);

    glColor3f(r-0.05, g-0.05, b-0.05);
    glVertex2f(x-0.015,h-0.025);
    glVertex2f(x-0.015,h-0.05);
    glVertex2f(x+0.235,h-0.05);
    glVertex2f(x+0.235,h-0.025);

    if (_night)
        glColor3f(1.0, 1.0, 0.1);
    else
        glColor3f(0.95, 0.95, 1.0);
    for (float wh = h - 0.215; wh > -0.05; wh-=0.14){
        glVertex2f(x+0.025,wh);
        glVertex2f(x+0.025,wh+0.125);
        glVertex2f(x+0.095,wh+0.125);
        glVertex2f(x+0.095,wh);

        glVertex2f(x+0.12,wh);
        glVertex2f(x+0.12,wh+0.125);
        glVertex2f(x+0.19,wh+0.125);
        glVertex2f(x+0.19,wh);
    }
    glEnd();

}

void building_side_road(){
    //Building side road
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.753, 0.753);
    glVertex2f(-1.0, -0.05);
    glVertex2f(-1.0, -0.12);
    glVertex2f(1.0, -0.12);
    glVertex2f(1.0, -0.05);

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.10);
    glVertex2f(-1.0, -0.12);
    glVertex2f(1.0, -0.12);
    glVertex2f(1.0, -0.10);
    glEnd();
}

void road(){
    //Main road lane 1
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.12);
    glVertex2f(-1.0, -0.32);
    glVertex2f(1.0, -0.32);
    glVertex2f(1.0, -0.12);

    //Main Road Strips 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.95, -0.30);
    glVertex2f(-0.95, -0.32);
    glVertex2f(-0.65, -0.32);
    glVertex2f(-0.65, -0.30);

    //Main Road Strips 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.55, -0.30);
    glVertex2f(-0.55, -0.32);
    glVertex2f(-0.25, -0.32);
    glVertex2f(-0.25, -0.30);

    //Main Road Strips 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.15, -0.30);
    glVertex2f(-0.15, -0.32);
    glVertex2f(0.15, -0.32);
    glVertex2f(0.15, -0.30);

    //Main Road Strips 4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.25, -0.30);
    glVertex2f(0.25, -0.32);
    glVertex2f(0.55, -0.32);
    glVertex2f(0.55, -0.30);

    //Main Road Strips 5
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.65, -0.30);
    glVertex2f(0.65, -0.32);
    glVertex2f(.95, -0.32);
    glVertex2f(.95, -0.30);
    glEnd();

    //Main road lane 2
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.32);
    glVertex2f(-1.0, -0.50);
    glVertex2f(1.0, -0.50);
    glVertex2f(1.0, -0.32);

    glEnd();
}

void car(float x, float y, float* color){
    glColor3fv(color);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
    glScalef(0.5,0.5,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.85+x, -0.20+y);
        glVertex2f(-0.55+x, -0.20+y);
        glVertex2f(-0.55+x, -0.13+y);
        glVertex2f(-0.60+x, -0.13+y);
        glVertex2f(-0.65+x, -0.03+y);
        glVertex2f(-0.75+x, -0.03+y);
        glVertex2f(-0.80+x, -0.03+y);
        glVertex2f(-0.85+x, -0.20+y);
        glVertex2f(-0.85+x, -0.13+y);
    glEnd();
    glPopMatrix();
    if (_night)
        glColor3f(1.0, 1.0, 0.1);
    else
        glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
    glScalef(0.5,0.5,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.61+x, -0.13+y);
        glVertex2f(-0.66+x, -0.04+y);
        glVertex2f(-0.79+x, -0.04+y);
        glVertex2f(-0.84+x, -0.13+y);
    glEnd();
    glPopMatrix();

    glColor3f(0.000, 0.545, 0.545);
    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
    glScalef(0.5,0.5,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.73+x, -0.13+y);
        glVertex2f(-0.72+x, -0.13+y);
        glVertex2f(-0.72+x, -0.04+y);
        glVertex2f(-0.73+x, -0.04+y);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.4+x,-0.1+y,0);
    glScalef(0.3,0.5,1);

        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.4+x,-0.1+y,0);
    glScalef(0.3,0.5,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.313+x,-0.1+y,0);
    glScalef(0.3,0.5,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.313+x,-0.1+y,0);
        glScalef(0.3,0.5,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    if(_night){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_car_1_x, 0.0f, 0.0f);
    glScalef(0.5,0.5,1);
        glBegin(GL_POLYGON);
            glVertex2f(-0.55, -0.165);
            glVertex2f(-0.55, -0.175);
            glVertex2f(-0.505, -0.195);
            glVertex2f(-0.505, -0.145);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void car_1(){
    glColor3d(0.000, 0.545, 0.545);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.85, -0.20);
        glVertex2f(-0.55, -0.20);
        glVertex2f(-0.55, -0.13);
        glVertex2f(-0.60, -0.13);
        glVertex2f(-0.65, -0.03);
        glVertex2f(-0.75, -0.03);
        glVertex2f(-0.80, -0.03);
        glVertex2f(-0.85, -0.13);
        glVertex2f(-0.85, -0.20);
    glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.61, -0.13);
        glVertex2f(-0.66, -0.04);
        glVertex2f(-0.79, -0.04);
        glVertex2f(-0.84, -0.13);
    glEnd();
    glPopMatrix();

    glColor3f(0.000, 0.545, 0.545);
    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.73, -0.13);
        glVertex2f(-0.72, -0.13);
        glVertex2f(-0.72, -0.04);
        glVertex2f(-0.73, -0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.80,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.80,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.62,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_1_x, 0.0f, 0.0f);
        glTranslatef(-0.62,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    if(_sun_y<-0.10){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_car_1_x, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.55, -0.165);
            glVertex2f(-0.55, -0.175);
            glVertex2f(-0.505, -0.195);
            glVertex2f(-0.505, -0.145);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void car_2(){
    glColor3d(0.545, 0.000, 0.000);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.54, -0.42);
        glVertex2f(-0.21, -0.42);
        glVertex2f(-0.20, -0.40);
        glVertex2f(-0.20, -0.13);
        glVertex2f(-0.21, -0.11);
        glVertex2f(-0.54, -0.11);
        glVertex2f(-0.55, -0.13);
        glVertex2f(-0.55, -0.40);
        glVertex2f(-0.54, -0.42);
	glEnd();
    glPopMatrix();

    glColor3d(0.902, 0.902, 0.980);
    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.52, -0.28);
        glVertex2f(-0.44, -0.28);
        glVertex2f(-0.44, -0.15);
        glVertex2f(-0.52, -0.15);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.41, -0.28);
        glVertex2f(-0.33, -0.28);
        glVertex2f(-0.33, -0.15);
        glVertex2f(-0.41, -0.15);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.30, -0.28);
        glVertex2f(-0.22, -0.28);
        glVertex2f(-0.22, -0.15);
        glVertex2f(-0.30, -0.15);
	glEnd();
    glPopMatrix();

    glColor3f(1.000, 0.647, 0.000);
    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53, -0.40);
        glVertex2f(-0.22, -0.40);
        glVertex2f(-0.225, -0.38);
        glVertex2f(-0.525, -0.38);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(_car_2_x, 0.0f, 0.0f);
    drawstring(-0.485, -0.354,0,"RUPAI TRAVELS");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
        glTranslatef(-0.48,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.045;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
        glTranslatef(-0.48,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
        glTranslatef(-0.27,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.045;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_car_2_x, 0.0f, 0.0f);
        glTranslatef(-0.27,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    if(_sun_y<-0.10){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_car_2_x, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.55, -0.405);
            glVertex2f(-0.55, -0.395);
            glVertex2f(-0.605, -0.385);
            glVertex2f(-0.605, -0.415);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void car_3(){
    glColor3d(0.118, 0.565, 1.000);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.55, -0.25);
        glVertex2f(0.50, -0.25);
        glVertex2f(0.50, -0.40);
        glVertex2f(0.85, -0.40);
        glVertex2f(0.85, -0.10);
        glVertex2f(0.65, -0.10);
        glVertex2f(0.55, -0.25);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.00);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.57, -0.25);
        glVertex2f(0.84, -0.25);
        glVertex2f(0.84, -0.12);
        glVertex2f(0.65, -0.12);
	glEnd();
    glPopMatrix();

    glColor3d(0.118, 0.565, 1.000);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.71, -0.25);
        glVertex2f(0.72, -0.25);
        glVertex2f(0.72, -0.12);
        glVertex2f(0.71, -0.12);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.57,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.57,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.78,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.78,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    if(_sun_y<-0.10){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_move_car_3, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(0.50, -0.385);
            glVertex2f(0.50, -0.375);
            glVertex2f(0.45, -0.365);
            glVertex2f(0.45, -0.395);
        glEnd();
        glPopMatrix();
    }
    glutSwapBuffers();
}

void road_border(){
    //River side road
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.753, 0.753);
    glVertex2f(-1.0, -0.50);
    glVertex2f(-1.0, -0.57);
    glVertex2f(1.0, -0.57);
    glVertex2f(1.0, -0.50);

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.55);
    glVertex2f(-1.0, -0.57);
    glVertex2f(1.0, -0.57);
    glVertex2f(1.0, -0.55);
    glEnd();
}

void river_border(){
    //River Side
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.871, 0.678);
    glVertex2f(-1.0, -0.73);
    glColor3f(1.000, 0.894, 0.769);
    glVertex2f(1.0, -0.73);
    glColor3f(1.000, 0.922, 0.804);
    glVertex2f(1.0, -0.77);
    glColor3f(0.871, 0.722, 0.529);
    glVertex2f(-1.0, -0.77);
    glEnd();
}

void river(){
    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 1.000);
    glVertex2f(1.0, -0.77);

    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-1.0, -0.77);

    glColor3f(0.498, 1.000, 0.831);
    glVertex2f(-1.0, -1.0);

    glColor3f(0.282, 0.820, 0.800);
    glVertex2f(1.0, -1.0);

    glEnd();
}

void tree_tri(float x){
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(x, -.026);
    glVertex2f(x+0.03, -.026);
    glVertex2f(x+.02, .174);
    glVertex2f(x+.01, .174);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(x-0.034, 0.115);
    glVertex2f(x+0.06, 0.115);
    glVertex2f(x+0.014, 0.302);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(x-0.034, 0.177);
    glVertex2f(x+0.06, 0.177);
    glVertex2f(x+0.014, 0.328);
    glEnd();
}

void tree(float x){
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(x, -.026);
    glVertex2f(x+0.03, -.026);
    glVertex2f(x+.02, .174);
    glVertex2f(x+.01, .174);
    glEnd();

    glPushMatrix();
        glTranslatef(x+0.032,0.154,0);
        glScalef(0.6,1,1);
        glColor3f(x+0., 0.804, 0.196);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(x-0.01,0.15,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(x+0.009,0.221,0);
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
}

void tree_flower(float x){
    glPushMatrix();
    glTranslatef(x,0,0);
    glScalef(0.6,1,1);
    glColor3f(0.824, 0.412, 0.118);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.030;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(x+0.022,0,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(x-0.019, 0.029,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(x+0.040,0.031,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(x+0.013, 0.047,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0435;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

}

void boat(){
    glPushMatrix();
    glTranslatef(_boat_1_x, 0.0f, 0.0f);
        glTranslatef(0.12, -1.03, 0.0);
        glScalef(0.50, 0.50, 0);
        glColor3f(0.8,0.4,0.3);
        glBegin(GL_POLYGON);
        glVertex2f(0.575, 0.45);
        glVertex2f(0.125, 0.45);
        glVertex2f(0.15, 0.65);
        glVertex2f(0.55, 0.65);

        glEnd();
        glPopMatrix();

    glPushMatrix();//start_pushpop
    glTranslatef(_boat_1_x, 0.0f, 0.0f);
        glTranslatef(0.0, -1.05, 0.0);
        glScalef(0.55, 0.55, 0);
        glPushMatrix();
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_QUADS);
        glVertex2f(0.3, 0.325);
        glVertex2f(0.8, 0.325);
        glVertex2f(0.95, 0.45);
        glVertex2f(0.15, 0.45);

        glEnd();
        glPopMatrix();

}

void ship(){
    glPushMatrix();//start_pushpop
    glTranslatef(_boat_2_x, 0.0f, 0.0f);
    glColor3f(0.8, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.470, -0.839);
    glVertex2f(-0.498, -0.768);
    glVertex2f(-0.539, -0.703);
    glVertex2f(-0.619, -0.703);
    glVertex2f(-0.673, -0.763);
    glVertex2f(-0.739, -0.836);
    glEnd();
    glPopMatrix();
    glPushMatrix();//start_pushpop
    glTranslatef(_boat_2_x, 0.0f, 0.0f);
    glColor3f(0.167, 0.165, 0.165);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75, -0.98);
    glVertex2f(-0.45, -0.98);
    glVertex2f(-0.40, -0.83);
    glVertex2f(-0.80, -0.83);
    glEnd();
    glPopMatrix();
}

void man(){
    glPushMatrix();
    glTranslatef(0.9, 0.036, 0.0f);
    glTranslatef(_man_x, 0.036, 0.0f);
    glScalef(0.6,1,1);
    glColor3f(0.647, 0.165, 0.165);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.025;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_man_x, 0.036, 0.0f);
    glColor3f(0.647, 0.165, 0.165);
    glBegin(GL_POLYGON);
    glVertex2f(0.895, 0.010);
    glVertex2f(0.890, -0.034);
    glVertex2f(0.909, -0.036);
    glVertex2f(0.903, 0.010);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.896, -0.036);
    glVertex2f(0.896, -0.076);
    glVertex2f(0.902, -0.078);
    glVertex2f(0.902, -0.034);
    glEnd();
    if (_rainy){
        glTranslatef(0.899, 0.039, 0.0f);
        glScalef(0.6,1,1);
        glColor3f(0.1, 0.1, 0.1);
        glBegin(GL_POLYGON);
        for(int i=0;i<100;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.08;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }
        glEnd();
    }

    glPopMatrix();
}

void fish(float x, float y){
    glPushMatrix();
    glScaled(0.5,0.5,1);
    glTranslatef(_fish_x, 0.0f, 0.0f);
    glTranslatef(x, y, 0.0f);
    glColor3f(0.3, 0.3, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.035, -0.901);
    glVertex2f(-0.083, -0.859);
    glVertex2f(-0.070, -0.896);
    glEnd();
    glBegin(GL_POLYGON);

    glVertex2f(-0.042, -0.901);
    glVertex2f(0.032, -0.901);
    glVertex2f(0.022, -0.880);
    glVertex2f(-0.003, -0.870);
    glVertex2f(-0.020, -0.872);
    glVertex2f(-0.026, -0.878);
    glVertex2f(-0.037, -0.901);
    glEnd();
    glPopMatrix();
}

void rain(){
    glPushMatrix();
    if (_rain_drop==1)
        glTranslatef(0.0,-0.04,0.0);
    else if (_rain_drop==2)
        glTranslatef(0.0,-0.08,0.0);
    glColor3f(1.0,1.0,1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (float x = -1.3; x < 1.3; x+=0.05){
        for (float y = 1.3; y > -1.3; y-= 0.14){
            glVertex2f(x, y);
            glVertex2f(x-0.002, y-0.01);
        }
    }

    glEnd();
    glPopMatrix();
}

void myDisplay(void){
    glLoadIdentity();
    sky();
    if (_night)
        stars();

    sun();
    birds();
    plane();

    field(-0.05,0.06);

    cloud(-0.78);
    cloud(0);
    cloud(0.2);
    cloud_right();

    tree_flower(0.963);
    tree_flower(0.735);
    tree_flower(-0.917);
    tree_flower(-0.763);
    tree_flower(0.912);
    tree_flower(0.782);
    tree_flower(0.833);
    tree_flower(0.864);
    tree_flower(0.684);
    tree_flower(0.630);
    tree_flower(-0.968);
    tree_flower(-0.868);
    tree_flower(-0.798);
    tree_flower(0.032);
    tree_flower(0.089);
    tree_flower(0.580);
    tree_flower(0.524);
    tree_flower(0.559);
    tree_flower(-0.993);

    tree(0.056);
    tree(0.654);
    tree(0.9);
    tree(-0.946);
    tree(0.779);

    tree_tri(-0.84);
    tree_tri(0.83);

    building(-0.75,0.65,0.1,0.4,0.1);
    building(-0.5,0.875,0.6,0.2,0.4);
    building(-0.315,0.76,0.8,0.0,0.4);
    building(-0.621,0.375,0.7,0.0,0.1);
    building(-0.43,0.375,0.7,0.0,0.1);
    building(0.299,0.612,0.3,0.3,0.4);
    building(-0.196,0.508,0.5,0.0,0.7);
    building(0.117,0.612,0.3,0.3,0.4);

    building_side_road();
    man();
    road();
    car_1();
    truck();
    car_2();
    field(-0.75,0.2);
    road_border();
    rail_track();
    train();
    river_border();
    river();
    fish(-0.343, -0.927);
    fish(-0.921, -0.815);
    fish(-0.865, -0.982);
    fish(0.423, -0.784);
    fish(0.890, -0.807);
    boat();
    ship();
    //car(m_x,m_y,new float[3]{0.0,0.54,0.545});
    if (_rainy)
        rain();
    glFlush();
}

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Pastel City");
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(20, update_sun, 0);
    glutTimerFunc(20, update_cloud_1, 0);
    glutTimerFunc(20, update_cloud_2, 0);
    glutTimerFunc(20, update_boat, 0);
    glutTimerFunc(20, update_plane, 0);
    glutTimerFunc(200, update_bird, 0);
    glutTimerFunc(20, update_train, 0);
    glutTimerFunc(20, update_car_1, 0);
    glutTimerFunc(20, update_fish, 0);
    glutTimerFunc(70, update_man, 0);
    glutTimerFunc(20, update_truck, 0);
    glutTimerFunc(20, update_car_2, 0);
    glutTimerFunc(20, update_ship, 0);
    myInit ();
    glutMainLoop();
}
