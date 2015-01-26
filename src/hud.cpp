/*
 * hud.cpp
 * Joel Wolfrath, 2015
 *
 * HUD drawing functions
 */

#include "hud.h"
#include <sstream>
#include <string>
#include <iostream>

using std::ostringstream;
using std::string;

void renderHUD(ATime* time, NavyMap* map){

    NavyMap::iterator nmi;

	GLfloat x_loc = -0.98f;
	GLfloat y_loc = 0.93f;
	GLfloat y_diff = 0.05f;

    ostringstream ss;
    string deploystat = "X ";

	glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f(x_loc, y_loc, 0.1f);

	ss << *time;
    string timestr = ss.str();

    for(size_t i = 0; i < timestr.size(); i++ ){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,
                                        timestr[i]);
    }

	y_loc -= y_diff;

    for (nmi=map->begin(); nmi!=map->end(); nmi++) {

        glRasterPos3f(x_loc, y_loc, 0.1f);

        if ((nmi->second)->isDeployed()) {
            deploystat = "Is Deployed: ";
        }
        else if ((nmi->second)->wasDeployed()) {
            deploystat = "Was Deployed: ";
        }
        else {
            deploystat = "Not Deployed: ";
        }

		deploystat += (nmi->first);

        for(size_t i = 0; i < deploystat.size(); i++ ){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,
                                        deploystat[i]);
        }

		y_loc -= y_diff;
    }
}
