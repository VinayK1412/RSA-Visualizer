#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<gl/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
void* currentfont;

enum { FRONTPAGE, ENCRYPTION, ENCRYPTIONINFO, WITHOUTENCRYPTION, EXIT };

int width = 650, height = 650;
int lineheight = 500;
int linemargin = 500;
int currentheight = 400;

void* font = GLUT_BITMAP_HELVETICA_12;
void* fonts[] =
{
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_12,
	GLUT_BITMAP_HELVETICA_10,
	GLUT_BITMAP_HELVETICA_18,

};

//To Display the text information
void output(int x, int y, const char* string, int j)
{
	int len, i;
	glColor3f(1, 1, 0);
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(fonts[j], string[i]);
}

//FIRST SCREEN - FRONT PAGE
void front_page()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClearColor(0.8, 0.2, 0.1, 0);
	output(230, 600, "RNS INSTITUTE OF TECHNOLOGY", 2);
	output(140, 550, "SUBJECT: COMPUTER GRAPHICS AND VISUALIZATION", 2);
	output(250, 450, "       CG MINI PROJECT ON      ", 2);
	output(220, 400, "    RSA ENCRYPTION AND DECRYPTION   ", 2);
	output(100, 200, "By: ", 3);
	output(125, 180, "VINAY KULKARNI[1RN18CS122]", 5);
	output(125, 150, "ADITYA KRISHNAGIRI[1RN17CS006]", 5);
	output(275, 50, "-> PRESS S TO start", 2);
	glutPostRedisplay();
	glFlush();
	glPopMatrix();
	glutSwapBuffers();

}

//Information page
void encryptioninfo()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClearColor(1, 0.1, 2.1, 1.0);
	output(170, 550, "The Message is :", 2);
	output(290, 500, "  'RNSIT'   ", 2);
	output(160, 450, "   The key is:        ", 2);
	output(290, 400, "p=13 & q=17    ", 2);
	output(100, 100, "-> Press W or w to view without RSA Encryption and decryption", 2);
	output(100, 50, "->Press E or e to view RSA Encryption and decryption", 2);
	glFlush();
	glPopMatrix();
	glutSwapBuffers();
}


/* Movement angles */
GLint movement_angle = 0, packet_angle = 0, head_angle = 0, 
	packet_angle1 = 0, head_angle1 = 0, packet_angle2 = 0, head_angle2 = 0, 
	packet_angle3 = 0, head_angle3 = 0, packet_angle4 = 0;
GLdouble mov_speed = 1;
GLint head_angle4 = 0, packet_angle5 = 0, head_angle5 = 0, packet_angle6 = 0, 
	head_angle6 = 0, packet_angle7 = 0, head_angle7 = 0, packet_angle8 = 40;
GLint movement_angle1 = 0, arrow_angle = 0, rev_arrow_angle = 0, phy_header_angle = 0,
	rev_phy_header_angle = 0, rev_phy_header_angle1 = 0, phy_header_angle1 = 0, 
	analog_sig_angle = 0, rev_analog_sig_angle = 0;

void animation_encryp(void)
{
	if ((movement_angle += mov_speed) >= 600)	//Movement
		movement_angle = 600;
	if ((arrow_angle += mov_speed) >= 150)	// outside
		arrow_angle = 150;
	if (arrow_angle == 150)
		if ((phy_header_angle += mov_speed) >= 100)		//Inside box sender side
			phy_header_angle = 100;
	if (phy_header_angle == 100)
		if ((phy_header_angle1 += mov_speed) >= 100)	//keys are added
			phy_header_angle1 = 100;
	if (phy_header_angle1 == 100)
		if ((analog_sig_angle += mov_speed) >= 100)		//Generate key without movement
			analog_sig_angle = 100;
	if (analog_sig_angle == 100)
		if ((movement_angle1 += mov_speed) >= 420)		//Generated key outside
			movement_angle1 = 420;
	if (movement_angle1 == 420)
		if ((rev_analog_sig_angle += mov_speed) >= 100)	//Key passed intruder below box
			rev_analog_sig_angle = 100;
	if (rev_analog_sig_angle == 100)
		if ((rev_phy_header_angle += mov_speed) >= 200)	//Key separated from code
			rev_phy_header_angle = 200;
	if (rev_phy_header_angle == 200)
		if ((rev_phy_header_angle1 += mov_speed) >= 100)	//Message sent to receiver outside box
			rev_phy_header_angle1 = 100;
	if (rev_phy_header_angle == 200)
		if ((rev_arrow_angle += mov_speed) >= 100)	//Increase height
			rev_arrow_angle = 100;
	glutPostRedisplay();
}

//Sender
void computer()
{
	//KEYBOARD
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_QUADS);
	glVertex2f(55, 340);
	glVertex2f(145, 340);
	glVertex2f(150, 350);
	glVertex2f(60, 350);
	glEnd();

	//CABINET
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(60, 355);
	glVertex2f(150, 355);
	glVertex2f(150, 370);
	glVertex2f(60, 370);
	glEnd();

	//CPU
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(75, 380);
	glVertex2f(135, 380);
	glVertex2f(135, 430);
	glVertex2f(75, 430);
	glEnd();

	//Monitor
	glColor3f(0.7, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2f(80, 385);
	glVertex2f(130, 385);
	glVertex2f(130, 425);
	glVertex2f(80, 425);
	glEnd();

	//Monitor Stand
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINES);
	glVertex2f(90, 370);
	glVertex2f(90, 380);
	glVertex2f(120, 370);
	glVertex2f(120, 380);
	glEnd();
}

//Receiver
void computer_dest()
{
	//Keyboard
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_QUADS);
	glVertex2f(545, 525);
	glVertex2f(635, 525);
	glVertex2f(640, 535);
	glVertex2f(550, 535);
	glEnd();

	//Cabinet
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(550, 540);
	glVertex2f(640, 540);
	glVertex2f(640, 555);
	glVertex2f(550, 555);
	glEnd();

	//CPU
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(565, 565);
	glVertex2f(625, 565);
	glVertex2f(625, 615);
	glVertex2f(565, 615);
	glEnd();

	//Monitor
	glColor3f(0.7, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2f(570, 570);
	glVertex2f(620, 570);
	glVertex2f(620, 610);
	glVertex2f(570, 610);
	glEnd();

	//Monitor stand
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINES);
	glVertex2f(580, 555);
	glVertex2f(580, 565);
	glVertex2f(610, 555);
	glVertex2f(610, 565);
	glEnd();


}

//Intruder
void computer_mid()
{
	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_QUADS);
	glVertex2f(300, 50);
	glVertex2f(410, 50);
	glVertex2f(420, 60);
	glVertex2f(305, 60);
	glEnd();

	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(305, 65);
	glVertex2f(415, 65);
	glVertex2f(415, 80);
	glVertex2f(305, 80);
	glEnd();

	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINE_LOOP);
	glVertex2f(320, 100);
	glVertex2f(400, 100);
	glVertex2f(400, 150);
	glVertex2f(320, 150);
	glEnd();

	glColor3f(0.7, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2f(325, 105);
	glVertex2f(395, 105);
	glVertex2f(395, 145);
	glVertex2f(325, 145);
	glEnd();

	glColor3f(0.75, 0.85, 0.65);
	glBegin(GL_LINES);
	glVertex2f(335, 80);
	glVertex2f(335, 100);
	glVertex2f(385, 80);
	glVertex2f(385, 100);
	glEnd();

}

//COMPUTE GCD
static long gcd(long m, long n)
{
	long r;
	while (n != 0)
	{
		r = m % n;
		m = n;
		n = r;

	}
	return m;
}

//encryption main logic
void encrypt(int x, int y, int z)
{
	string msg = "RNSIT";
	long encrypted[100];
	long num[100];
	int p = 13, q = 17, phi, i, len, e, d, j;
	int n = p * q;
	phi = (p - 1) * (q - 1);
	for (i = 2; i < phi; i++)
		if (gcd(i, phi) == 1)
			break;
	e = i;
	for (i = 2; i < phi; i++)
		if ((e * i - 1) % phi == 0)
			break;
	d = i;
	len = msg.length();

	for (i = 0; i < len; i++)
		num[i] = msg[i];

	for (i = 0; i < len; i++)
	{
		encrypted[i] = 1;
		for (j = 0; j < e; j++)
		{
			encrypted[i] = (encrypted[i] * num[i] % n);
		}
	}
	glRasterPos3i(x, y, z);
	for (i = 0; encrypted[i] != '\0'; i++)
		glutBitmapCharacter(font, encrypted[i]);
	glutPostRedisplay();
	glFlush();
}

//call encryption method
void cipher()
{
	glColor3f(1, 1, 0);
	glPushMatrix();
	glScalef(40, 20, 0.5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	encrypt(-1, 0, 0);
	glPopMatrix();
}

void cipher2()
{
	glColor3f(1, 1, 0);
	glPushMatrix();
	glScalef(40, 20, 0.5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, "RNSIT", 2);
	glPopMatrix();

}

void message_data()
{
	glColor3f(1, 1, 0);
	glPushMatrix();
	glScalef(40, 20, 0.5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, "RNSIT", 2);
	glPopMatrix();

}

//Encryption keys
void message_key(void)
{
	glColor3f(0, 1, 0);
	glPushMatrix();
	glScalef(20, 20, 0.5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, " p=13 , q=17", 2);
	glPopMatrix();
}

//Decyrption
void decrypt(float x, float y, float z)
{
	string msg = "r[FcC";
	long encrypted[100];
	long decrypted[100];
	long num[100];
	int p = 13, q = 17, phi = 0, i = 0, len = 0, e = 0, d = 0, j = 0;
	int n = p * q;
	phi = (p - 1) * (q - 1);
	for (i = 2; i < phi; i++)
		if (gcd(i, phi) == 1)
			break;
	e = i;
	for (i = 2; i < phi; i++)
		if ((e * i - 1) % phi == 0)
			break;
	d = i;
	len = msg.length();

	for (i = 0; i < len; i++)
		num[i] = msg[i];
	glRasterPos3i(x, y, z);

	for (int i = 0; i < len; i++)
	{
		decrypted[i] = 1;
		for (int j = 0; j < d; j++)
		{
			decrypted[i] = ((decrypted[i] * msg[i]) % n);
		}
	}
	for (i = 0; i <= len; i++)
		glutBitmapCharacter(font, (char)decrypted[i]);
	glutPostRedisplay();
	glFlush();

}

//call decryption method
void messagedata2()
{
	glColor3f(1, 1, 0);
	glPushMatrix();
	glScalef(40, 20, 0.5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	decrypt(-1, 0, 0);
	glPopMatrix();

}

//display error
void message_data3()
{
	glColor3f(1, 1, 0);
	glPushMatrix();
	glScalef(40, 20, 0.5);
	glTranslatef(3, 14, 0);
	glutWireCube(2);
	output(-1, 0, "ERROR", 2);
	glPopMatrix();

}

void withoutencryption()              //displays on output screen
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glColor3f(0, 1, 0);
	output(220, 670, "Without using RSA Encryption And Decryption", 2);

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(-30, 200, 0);
	output(75, 440, "Sender", 2);
	computer();
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	output(565, 630, "Receiver", 2);
	computer_dest();
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	output(320, 190, "Intruder", 2);
	computer_mid();
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	glScalef(70, 40, 0.5);
	glTranslatef(1.5, 7, 0);
	glutWireCube(2);
	glPopMatrix();

	if (phy_header_angle1 != 100)
	{
		glPushMatrix();
		glTranslatef(0, -phy_header_angle1, 0);
		glPushMatrix();
		glTranslatef(0, -arrow_angle, 0);
		glTranslatef(0, 150, 0);
		message_data();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(phy_header_angle, 0, 0);
		glTranslatef(-100, 0, 0);

		glPopMatrix();
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(movement_angle1, 0, 0);
	if (phy_header_angle1 == 100)
	{
		glPushMatrix();
		if (movement_angle1 >= 420)
		{
			glTranslatef(0, rev_analog_sig_angle, 0);
		}
		glTranslatef(0, -analog_sig_angle, 0);
		if (rev_analog_sig_angle != 100)
			cipher2();
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(movement_angle1, 0, 0);
	if (phy_header_angle1 == 100)
	{
		glPushMatrix();
		glScalef(50, 30, 0.5);
		glTranslatef(2.5, 2.5, 0);
		glutWireCube(2);
		glPopMatrix();
	}
	glPopMatrix();
	if (rev_analog_sig_angle == 100)
	{
		glPushMatrix();
		glTranslatef(450, rev_phy_header_angle1, 0);
		glPushMatrix();
		glTranslatef(0, rev_arrow_angle, 0);
		glTranslatef(0, 0, 0);
		message_data3();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(rev_phy_header_angle, 0, 0);
		glTranslatef(-10, 0, 0);
		glPopMatrix();
		glPopMatrix();

	}
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(450, 0, 0);
	glScalef(70, 40, 0.5);
	glTranslatef(1.5, 7, 0);
	glutWireCube(2);
	glPopMatrix();
	animation_encryp();
	glFlush();
	glutSwapBuffers();
}

//encryption in output screen
void encryption()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.5, 0, 0.5, 1);

	glColor3f(1, 1, 1);
	output(150, 670, "RSA ENCRYPTION AND DECRYPTION PROCESS", 2);

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(-30, 200, 0);
	output(75, 440, "Sender", 2);
	computer();
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	output(565, 630, "Receiver", 2);
	computer_dest();
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	output(320, 190, "Intruder", 2);
	computer_mid();
	glPopMatrix();

	glColor3f(1, 1, 1);
	glPushMatrix();
	glScalef(70, 40, 0.5);
	glTranslatef(1.5, 7, 0);
	glutWireCube(2);
	glPopMatrix();

	if (phy_header_angle1 != 100)
	{
		glPushMatrix();
		glTranslatef(0, -phy_header_angle1, 0);
		glPushMatrix();
		glTranslatef(0, -arrow_angle, 0);
		glTranslatef(0, 150, 0);
		message_data();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(phy_header_angle, 0, 0);
		glTranslatef(-100, 0, 0);
		message_key();
		glPopMatrix();
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(movement_angle1, 0, 0);

	if (phy_header_angle1 == 100)
	{
		glPushMatrix();
		if (movement_angle1 >= 420)
		{
			glTranslatef(0, rev_analog_sig_angle, 0);
		}
		glTranslatef(0, -analog_sig_angle, 0);
		if (rev_analog_sig_angle != 100)
			cipher();
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(movement_angle1, 0, 0);

	if (phy_header_angle1 == 100)
	{
		glPushMatrix();
		glScalef(50, 30, 0.5);
		glTranslatef(2.5, 2.5, 0);
		glutWireCube(2);
		glPopMatrix();
	}
	glPopMatrix();

	if (rev_analog_sig_angle == 100)
	{
		glPushMatrix();
		glTranslatef(450, rev_phy_header_angle1, 0);
		glPushMatrix();
		glTranslatef(0, rev_arrow_angle, 0);
		glTranslatef(0, 0, 0);
		messagedata2();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(rev_phy_header_angle, 0, 0);
		glTranslatef(-10, 0, 0);
		if (rev_phy_header_angle < 200)
			message_key();
		glPopMatrix();
		glPopMatrix();

	}
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(450, 0, 0);
	glScalef(70, 40, 0.5);
	glTranslatef(1.5, 7, 0);
	glutWireCube(2);
	glPopMatrix();
	animation_encryp();
	glFlush();
	glutSwapBuffers();


}

//initialization
void myinit()
{
	glColor3f(1, 0, 0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 700, 0, 700);

}

//call front page
void display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	front_page();
	glFlush();
	glutSwapBuffers();

}

//keys defined
void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'S':
	case 's': glutDisplayFunc(encryptioninfo);
		break;
	case 'W':
	case'w':glutDisplayFunc(withoutencryption);
		break;
	case'E':
	case'e':glutDisplayFunc(encryption);
		break;
	case'Q':
	case'q':
		exit(0);

	}
	glutPostRedisplay();
}

//Menu
static void menu(int mode)
{
	switch (mode)
	{
	case FRONTPAGE:glutDisplayFunc(front_page);
		break;
	case ENCRYPTIONINFO:glutDisplayFunc(encryptioninfo);
		break;
	case WITHOUTENCRYPTION:glutDisplayFunc(withoutencryption);
		break;
	case ENCRYPTION:glutDisplayFunc(encryption);
		break;
	case EXIT:exit(0);
	}
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(0, 0);
	glClearColor(0.7, 0.5, 0.5, 1);

	glutCreateWindow("ENCRYPTION");
	glutKeyboardFunc(key);

	myinit();
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("Front Page", FRONTPAGE);

	glutAddMenuEntry("Encryptioninfo", ENCRYPTIONINFO);
	glutAddMenuEntry("Without Encryption", WITHOUTENCRYPTION);
	glutAddMenuEntry("With Encryption", ENCRYPTION);
	glutAddMenuEntry("Exit", EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

}