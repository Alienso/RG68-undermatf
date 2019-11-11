//PREUZETO SA INTERNETA. FUNKCIJA ZA ISPISIVANJE TEKSTA NA EKRAN

#ifndef _TEKST_H
#define _TEKST_H

#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>

typedef enum {
   MODE_BITMAP,
   MODE_STROKE
} mode_type;

static mode_type mode;
static int font_index;

void
print_bitmap_string(void* font, char* s)
{
   if (s && strlen(s)) {
      while (*s) {
         glutBitmapCharacter(font, *s);
         s++;
      }
   }
}

void
print_stroke_string(void* font, char* s)
{
   if (s && strlen(s)) {
      while (*s) {
         glutStrokeCharacter(font, *s);
         s++;
      }
   }
}

void
draw_text(char niska[], GLfloat x_val, GLfloat y_val,float r_,float g_,float b_){

   mode = MODE_BITMAP;
   font_index = 3;   

   char string[8][256];
   unsigned int i, j;
   unsigned int count;
   void* bitmap_fonts[7] = {
      GLUT_BITMAP_9_BY_15,
      GLUT_BITMAP_8_BY_13,
      GLUT_BITMAP_TIMES_ROMAN_10,
      GLUT_BITMAP_TIMES_ROMAN_24,
      GLUT_BITMAP_HELVETICA_10,
      GLUT_BITMAP_HELVETICA_12,
      GLUT_BITMAP_HELVETICA_18     
   };

   char* bitmap_font_names[7] = {
      "GLUT_BITMAP_9_BY_15",
      "GLUT_BITMAP_8_BY_13",
      "GLUT_BITMAP_TIMES_ROMAN_10",
      "GLUT_BITMAP_TIMES_ROMAN_24",
      "GLUT_BITMAP_HELVETICA_10",
      "GLUT_BITMAP_HELVETICA_12",
      "GLUT_BITMAP_HELVETICA_18"     
   };

   void* stroke_fonts[2] = {
      GLUT_STROKE_ROMAN,
      GLUT_STROKE_MONO_ROMAN
   };

   void* stroke_font_names[2] = {
      "GLUT_STROKE_ROMAN",
      "GLUT_STROKE_MONO_ROMAN"
   };

   GLfloat x, y, ystep, yild, stroke_scale;

   /* Set up some strings with the characters to draw. */
   /*count = 0;
   for (i=1; i < 32; i++) {
      string[0][count] = i;
      count++;
   }
   string[0][count] = '\0';*/

   count = 0;
   for (i=0; niska[i]!='\0';i++){
	string[0][count] = niska[i];
	count++;
   }
   string[0][count]='\0';


   /* Draw the strings, according to the current mode and font. */
   glColor4f(r_, g_, b_, 0.0);
   x = x_val;
   y = y_val;
   ystep  = 100.0;
   yild   = 20.0;
   if (mode == MODE_BITMAP) {
      glRasterPos2f(-150, y+1.25*yild);
      print_bitmap_string(
         bitmap_fonts[font_index], bitmap_font_names[font_index]);
      for (j=0; j<7; j++) {
         glRasterPos2f(x, y);
         print_bitmap_string(bitmap_fonts[font_index], string[j]);
         y -= yild;
      }
   }
   else {
      stroke_scale = 0.1f;
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix(); {
         glTranslatef(x, y+1.25*yild, 0.0);
         glScalef(stroke_scale, stroke_scale, stroke_scale);
         print_stroke_string(
            stroke_fonts[font_index], stroke_font_names[font_index]);
      } glPopMatrix();
      glPushMatrix(); {
         glTranslatef(x, y, 0.0);
         for (j=0; j<4; j++) {
            glPushMatrix(); {
               glScalef(stroke_scale, stroke_scale, stroke_scale);
               print_stroke_string(stroke_fonts[font_index], string[j]);
            } glPopMatrix();
            glTranslatef(0.0, -yild, 0.0);
         }
         glTranslatef(0.0, -ystep, 0.0);
      } glPopMatrix();
   }
}

#endif
