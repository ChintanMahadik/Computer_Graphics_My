/*
 * sunset_tp.c
 *
 *  Created on: Apr 9, 2014
 *      Author: chintan
 */


/*
 * my project.c
 *
 *  Created on: Apr 5, 2014
 *      Author: chintan
 *
 */


#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.142

float heli_x;
float sun_radius=0,hlf_sun_radius=0;
int flag=0;
float bfly=0,bscale=1;
float scaling_air =1,x_scaling_sea=1,y_scaling_sea=1;
float moonfactor,t;
float sunlimit,moonlimit;
float speedsea=0.4;
float size;
float i=0,j=0,a,b,c,d,e,f,ms1,ms2,ms3;
float moon_angle=1,x_speed_air,y_speed_air;

float hs,hss;


void drawCircle(GLfloat x, GLfloat y, GLfloat radius)//direct circle
{

	int i;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++)
	{
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);

		}
	glEnd();
	glFlush();
}

void halfCircle(float k,float j,float r)
{


			    float p,x,y;
			    glBegin(GL_POLYGON);
			 //   glColor3f(1.1,0.1,0.0);

 		        x=0;
			    y=r;

			    p=1.25-r;
			    do
			    {
			    	printf("\n x,y is %f %f",x,y);

			    	glVertex2f(k+x,j+y);
			    	glVertex2f(k+y,j+x);
			    	//glVertex2f(k+y,j-x);
			    	glVertex2f(k-y,j+x);
			    	//glVertex2f(k-x,j-y);
			    	//glVertex2f(k-y,j-x);
			    	//glVertex2f(k+x,j-y);
			    	glVertex2f(k-x,j+y);


			    	if(p<0)
			    	{
			    		x=x+1;

			    		p=p+2*x+1;

			    	}
			    	else
			    	{
			    		x=x+1;
			    		y=y-1;
			    		p=p+2*x-2*y+1;

			    	}



			    }
			    while(x<y);


			    glEnd();




}



////////////Aeroplane/////////////////////////////////////////////

void aeroplane()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);
   //sky night
    glBegin(GL_POLYGON);

    glColor3f(a,b,c);
    		glVertex2f(0,100);
    		glVertex2f(0,500);
    		glVertex2f(800,500);
    		glVertex2f(800,100);

    		 	 	 	glColor3f(d,e,f);
    					glVertex2f(0,200);
    					glVertex2f(0,500);
    					glVertex2f(800,500);
    					glVertex2f(800,200);
    glEnd();


	  //ROAD//
		glBegin(GL_POLYGON);
		glColor3f(0.5,0.5,0.5);

			glVertex2f(0,0);
			glVertex2f(0,100);
			glVertex2f(800,100);
			glVertex2f(800,0);

		glColor3f(0.1,0.1,0.1);

			glVertex2f(0,50);
			glVertex2f(0,100);
			glVertex2f(800,100);
			glVertex2f(800,50);


		glEnd();

		///////////////mountains//////////////
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.6,0.3,0);
		glVertex2f(0,100);
		glVertex2f(20,140);
		glColor3f(0,0,0);
		glVertex2f(40,100);

		glColor3f(0.6,0.3,0);
		        glVertex2f(40,100);
				glVertex2f(60,120);
				glColor3f(0,0,0);
				glVertex2f(80,100);

				glColor3f(0.6,0.3,0);
				        glVertex2f(80,100);
						glVertex2f(100,170);
						glColor3f(0,0,0);
						glVertex2f(120,100);

						glColor3f(0.6,0.3,0);
						       glVertex2f(120,100);
								glVertex2f(140,120);
								glColor3f(0,0,0);
								glVertex2f(160,100);

								glColor3f(0.6,0.3,0);
								        glVertex2f(160,100);
										glVertex2f(180,150);
										glColor3f(0,0,0);
										glVertex2f(200,100);

										glColor3f(0.6,0.3,0);
										        glVertex2f(200,100);
												glVertex2f(220,120);
												glColor3f(0,0,0);
												glVertex2f(240,100);

												glColor3f(0.6,0.3,0);
												        glVertex2f(240,100);
														glVertex2f(260,180);
														glColor3f(0,0,0);
														glVertex2f(280,100);

														glColor3f(0.6,0.3,0);
														         glVertex2f(280,100);
																glVertex2f(300,120);
																glColor3f(0,0,0);
																glVertex2f(320,100);

		glEnd();




		//road stripes//
		glBegin(GL_QUADS);

		glColor3f(1,1,1);
		glVertex2f(0,45);
		glVertex2f(0,50);
		glVertex2f(40,50);
		glVertex2f(40,45);


				glVertex2f(80,45);
				glVertex2f(80,50);
				glVertex2f(120,50);
				glVertex2f(120,45);


						glVertex2f(160,45);
						glVertex2f(160,50);
						glVertex2f(200,50);
						glVertex2f(200,45);


								glVertex2f(240,45);
								glVertex2f(240,50);
								glVertex2f(280,50);
								glVertex2f(280,45);



										glVertex2f(320,45);
										glVertex2f(320,50);
										glVertex2f(360,50);
										glVertex2f(360,45);

		glEnd();



		////////////moon & sun/////////////////////

									  glMatrixMode(GL_MODELVIEW);

								      glPushMatrix();
								      glRotatef(moon_angle,0,0,1);
								      glBegin(GL_POLYGON);
								      glColor3f(ms1,ms2,ms3);
								      drawCircle(270,210,30);

								      glEnd();
								      glPopMatrix();



				///////birds flying/////////////////

										 glMatrixMode(GL_MODELVIEW);

									      glPushMatrix();
									     glTranslatef(-x_speed_air*0.5,-y_speed_air*0.5,0);

									    glScalef(bscale,bscale,0);


										glBegin(GL_TRIANGLE_STRIP);
										glColor3f(0,0,0);
								//////bird 1
										glVertex2f(220,220);
										glVertex2f(230,200);
										glVertex2f(230,205);

										glVertex2f(230,200);
										glVertex2f(230,205);
										glVertex2f(240,220);
										glEnd();
								//////bird 2
										glBegin(GL_TRIANGLE_STRIP);
												glColor3f(0,0,0);

										glVertex2f(250,220);
									    glVertex2f(260,200);
										glVertex2f(260,205);

										glVertex2f(260,200);
										glVertex2f(260,205);
										glVertex2f(270,220);



										glEnd();

										 glPopMatrix();
								//////end of bird//////////////

		////////////////plane////////////////////

		 glMatrixMode(GL_MODELVIEW);

		  glPushMatrix();


		glTranslatef(x_speed_air,y_speed_air,0);
        glScalef(scaling_air,scaling_air,0);
			glBegin(GL_POLYGON);
			glColor3f(1,0,0);

			glVertex2f(10,60);
			glVertex2f(10,70);
			glColor3f(0,0,0);

			glVertex2f(15,70);
			glVertex2f(16,60);
			glEnd();

			glBegin(GL_POLYGON);
			glColor3f(1,0,0);
			glVertex2f(10,60);
			glVertex2f(10,62);
			glColor3f(0,0,0);
			glVertex2f(50,68);
			glVertex2f(55,65);
			glVertex2f(50,60);

			glEnd();

//wing plates////
			glBegin(GL_POLYGON);
					glColor3f(1,0.0,0);

					glVertex2f(35,66);
					glColor3f(0,0,0);
					glVertex2f(33,80);
					glVertex2f(35,80);
					glVertex2f(45,67);

					glEnd();

					glBegin(GL_POLYGON);

						glColor3f(1,0.0,0);

						glVertex2f(35,62);
						glColor3f(0,0,0);
						glVertex2f(33,40);
						glVertex2f(35,40);

						glVertex2f(45,64);
						glEnd();

						//windows////
						glBegin(GL_POINTS);
						glColor3f(1,1,1);
						drawCircle(20,62,1);
						drawCircle(24,62,1);
						drawCircle(28,62.5,1);
						drawCircle(32,63,1);
						drawCircle(36,64,1);
						drawCircle(50,65,1);



						glScalef(1,1,0);

						glEnd();


						glPopMatrix();
						//end of plane//////


//car on runway//////////////////////////

			glMatrixMode(GL_MODELVIEW);

			glPushMatrix();
			glTranslatef(heli_x,0,0);


			glColor3f(0.1,0.1,0.1);
			drawCircle(-25,50,5);

			glColor3f(0.1,0.1,0.1);
			drawCircle(-5,50,5);

			glColor3f(0,0.0,1);


			glBegin(GL_QUADS);
			glColor3f(0.2,0.8,0.2);

			glVertex2f(-30,50);
			glVertex2f(-30,65);
			glVertex2f(0,65);
			glVertex2f(0,50);

			glVertex2f(0,65);
			glVertex2f(5,60);
			glVertex2f(5,53);
			glVertex2f(0,50);
			glEnd();


			glBegin(GL_LINES);
			glColor3f(1,1,1);
			glVertex2f(-2,65);
			glVertex2f(-2,50);
			glEnd();


			glColor3f(1,1,1);
			glBegin(GL_TRIANGLE_STRIP);
			glVertex2f(0,62);
			glVertex2f(0,55);
			glVertex2f(4,55);


			glEnd();

			///////////car windows//////////////

			glColor3f(1,1,1);
			drawCircle(-25,60,2);

			glColor3f(1,1,1);
			drawCircle(-18,60,2);

			glColor3f(1,1,1);
			drawCircle(-12,60,2);

			glColor3f(1,1,1);
			drawCircle(-5,60,2);

			glPopMatrix();

/////////////end of car//////////////////////



						                        //stars//
												  	    glBegin(GL_POLYGON);
												  	    glColor3f(1,1,1);

												  	       drawCircle(100,280,1);
												  	       drawCircle(10,250,0.8);
												  	       drawCircle(200,270,1);
												  	       drawCircle(290,270,0.8);
												  	       drawCircle(250,290,0.8);
												  	       drawCircle(30,290,1);
												  	       drawCircle(150,290,1);
												  	       drawCircle(170,280,0.8);
												  	       drawCircle(120,275,1);
												  	   	   drawCircle(70,260,0.8);
												  	   	   drawCircle(180,260,0.8);
												  	       drawCircle(120,290,1);
												  	       drawCircle(270,270,0.8);

												  	    glEnd();
												  	    //end of star///////////////////////////////////



    glFlush();

	glutSwapBuffers();


}

///////////////////////////////boat//////////////////////////////////
void boat()
{



//shift the boat to right// by a factor of 0.1//

	 glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
	 	    glClear(GL_COLOR_BUFFER_BIT);
		 	//  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

 			//point of sun to start//
 			sunlimit=220;
 			moonlimit=130;


 			//sky//
 				 		glBegin(GL_POLYGON);


 				 		           glColor3f(a,b,c);
 				 		    		glVertex2f(0,100);
 				 		    		glVertex2f(0,500);
 				 		    		glVertex2f(800,500);
 				 		    		glVertex2f(800,100);

 				 		    		 	 	 	glColor3f(d,e,f);
 				 		    					glVertex2f(0,200);
 				 		    					glVertex2f(0,500);
 				 		    					glVertex2f(800,500);
 				 		    					glVertex2f(800,200);

 				 		glEnd();

 			//////////////////////broken star //////////////////
 			 			 										glMatrixMode(GL_MODELVIEW);

 			 			 				 						  	 glPushMatrix();
 			 			 				 						  	 glColor3f(1,1,1);
 			 			 				 						  	 glRotatef(bfly,0,0,0);
 			 			 				 						  	 //glTranslatef(starbrk,0,0);
 			 			 				 						    glBegin(GL_POLYGON);

 			 			 				 						   drawCircle(320,320,5);
 			 			 				 						   glEnd();
 			 			 				 						  glPopMatrix();
 			 			 				 						  	    ////////////end///////////


	 	  //sea//
	 		glBegin(GL_POLYGON);
	 		glColor3f(0,0.1,0.4);

	 			glVertex2f(0,0);
	 			glVertex2f(0,100);
	 			glVertex2f(800,100);
	 			glVertex2f(800,0);

	 		glColor3f(0.0,0.0,0.0);

	 			glVertex2f(0,50);
	 			glVertex2f(0,100);
	 			glVertex2f(800,100);
	 			glVertex2f(800,50);


	 		glEnd();







	 		//sun falling frm top//

	 						    glBegin(GL_POLYGON);
	 						    glColor3f(hs,0,0);

	 						    sunlimit=sunlimit-0.5*moonfactor;

	 						    	if(sunlimit>=130)
	 						    	drawCircle(145,sunlimit,sun_radius);
	 						    	else
	 						    	{
	 						    		 glColor3f(hs,hss,0);

	 						    				  halfCircle(140,100,hlf_sun_radius);//sun paused//

	 			//beginning of moon starts after sun has stopped//

	 						    				  //beginning of moon//

	 						    				 				  		glColor3f(1,1,1);
	 						    				 				  		moonlimit=moonlimit+0.1*moonfactor;

	 						    				 				  		if(moonlimit<250)
	 						    				 				  		drawCircle(250,moonlimit,25);
	 						    				 				  		else
	 						    				 				  		{
	 						    				 				  			glColor3f(1,1,1);

	 						    				 				  		      drawCircle(250,250,25);


	 						    				 				  		}


	 						    	}

	 			glEnd();



//////////////////////boat/.////////
	 														glMatrixMode(GL_MODELVIEW);

	 				 						 	 			glPushMatrix();

	 				 						 	 		glTranslatef(speedsea,0,0);
	 				 						 	 		glScalef(x_scaling_sea,y_scaling_sea,0);

	 				 						 	 			glBegin(GL_QUADS);

	 				 						 	 			glColor3f(0,0,0);

	 				 						 	 			glVertex2f(20,100);
	 				 						 	 			glVertex2f(0,120);
	 				 						 	 			glVertex2f(100,120);
	 				 						 	 			glVertex2f(80,100);


	 				 						 	 			//glBegin(GL_QUADS);
	 				 						 	 			glVertex2f(70,120);
	 				 						 	 			glVertex2f(70,200);
	 				 						 	 			glVertex2f(85,130);
	 				 						 	 			glVertex2f(70,120);

	 				 						 	 			glEnd();
	 				 						 	 			 glPopMatrix();



	 		//stars//
	 				 		     	glMatrixMode(GL_MODELVIEW);
	 				 		     	glPushMatrix();
	 						  	    glBegin(GL_POLYGON);
	 						  	    glColor3f(1,1,1);

	 						  	       drawCircle(100,280,1);
	 						  	       drawCircle(10,250,0.8);
	 						  	      drawCircle(200,270,1);
	 						  	       drawCircle(290,270,0.8);
	 						  	       drawCircle(250,290,0.8);
	 						  	       drawCircle(30,290,1);
	 						  	       drawCircle(150,290,1);
	 						  	       drawCircle(170,280,0.8);
	 						  	       drawCircle(120,275,1);
	 						  	   	   drawCircle(70,260,0.8);
	 						  	   	   drawCircle(180,260,0.8);
	 						  	       drawCircle(120,290,1);
	 						  	       drawCircle(270,270,0.8);

	 						  	    glEnd();
	 						  	 glPopMatrix();
	 						  	    //end of star///////////////////////////////////






	glFlush();
	glutSwapBuffers();


}

void display()
{
	 glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
	 glClear(GL_COLOR_BUFFER_BIT);
	 glBegin(GL_POLYGON);


	 if(flag==0)
boat();
	 else if(flag==1)
aeroplane();

glEnd();
}


void timer(int v)
{
	if(speedsea<290)
	{
speedsea=speedsea+0.5;
	x_scaling_sea-=0.0001;
	y_scaling_sea-=0.0001;
	//bfly+=0.5;
	//starbrk+=1;
	}
	else
	{
    x_scaling_sea=1;
    y_scaling_sea=1;
		speedsea=0;
		bfly=0;

	}

moonfactor+=0.1;

if(x_speed_air<270)
{
	x_speed_air+=0.2;
	y_speed_air+=0.1;
	scaling_air-=0.0005;

	bscale-=0.0001;
 if(x_speed_air>100)
	{
		heli_x++;
	}

}

else
{
	x_speed_air=0;
	y_speed_air=0;
	scaling_air=1;
	heli_x=0;
	bscale=1;
}

moon_angle+=0.05;


    glutPostRedisplay();

  glutTimerFunc(10,timer,v);

}



void Special(int key, int x, int y)
{
	switch (key)
	{
		        case GLUT_KEY_F8 : speedsea+=1;
							x_scaling_sea-=0.008;
							y_scaling_sea-=0.001;
							                break;
		        case GLUT_KEY_F5 :speedsea-=1;
							x_scaling_sea+=0.008;
							y_scaling_sea+=0.0005;
							                 break;

		        case GLUT_KEY_F6 : moonfactor+=2;
		                                     break;
	            case GLUT_KEY_F7 :moonfactor-=3;
	                                         break;



		        case GLUT_KEY_UP : x_speed_air+=2;
				                    y_speed_air+=1;
				                    scaling_air-=0.0005;
				                    bscale-=0.005;break;

				case GLUT_KEY_DOWN :x_speed_air-=4;
									y_speed_air-=2;
									 scaling_air+=0.005;
									 bscale+=0.005;
									break;

				case GLUT_KEY_LEFT:moon_angle+=0.1;
									break;
				case GLUT_KEY_RIGHT:moon_angle-=0.5;
											break;

				case GLUT_KEY_F12: flag=1;
									break;

				case GLUT_KEY_F11: flag=0;
							         break;

				case GLUT_KEY_F9: bfly+=1;///////broken stars/////////
								  break;


	}

}



void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {

 a=0;
 b=0;
 c=0.4;
 d=0.2;
 e=0.8;
 f=0.8;
 ms1=1;
 ms2=1;
 ms3=1;
 hs=0;
 hss=0;
 sun_radius=0;
 hlf_sun_radius=0;
  }
  else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {


a=1;
b=0.4;
c=0;
d=0;
e=0;
f=0.5;

ms1=1;
ms2=0;
ms3=0;

hs=1;
hss=0.2;
sun_radius=20;
hlf_sun_radius=20;

 }
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("@@@  BOAT # SUNSET # AEROPLANE  @@@");
    gluOrtho2D(0,300,0,300);
    glutDisplayFunc(display);
   glutTimerFunc(10,timer,0);
    glutMouseFunc(mouse);
    glutSpecialFunc(Special);

    glutMainLoop();
    return 0;
}
