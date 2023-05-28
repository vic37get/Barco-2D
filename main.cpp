/*
 * Computacao Grafica
 * Codigo Exemplo: Barco 2D
 * Autor: Victor Ribeiro da Silva
 */
 
// Bibliotecas utilizadas pelo OpenGL
#ifdef __APPLE__ // MacOS
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else // Windows e Linux
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <cstdlib>
#include <cmath>
#define ESC 27

//Variaveis Globais usadas para definicao de cores
float R,G,B;


// Declaracoes antecipadas (forward) de funcoes para as funcoes callback do OpenGL
void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void keyboard_special(int key, int x, int y);
void display(void);

/*
 * Funcao principal
 */
int main(int argc, char** argv){
    glutInit(&argc, argv); // Passagens de parametros C para o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize (1024, 768);  // Tamanho da janela do OpenGL
    glutInitWindowPosition (100, 100); //Posicao inicial da janela do OpenGL
    glutCreateWindow ("Computacao Grafica: Barco 2D"); // Da nome para uma janela OpenGL
    init(); // Chama a funcao init();
    glutReshapeFunc(reshape); //funcao callback para redesenhar a tela
    glutDisplayFunc(display); //funcao callback de desenho
    glutKeyboardFunc(keyboard); //funcao callback do teclado
    glutMainLoop(); // executa o loop do OpenGL
    return EXIT_SUCCESS; // retorna 0 para o tipo inteiro da funcao main()
}

/*
 * Inicializa alguns parametros do GLUT
 */
void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
    R = 0.0;
    G = 0.0;
    B = 0.0;
}

/*
 * Ajusta a projecao para o redesenho da janela
 */
void reshape(int w, int h)
{
	// Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    // Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);

    glOrtho (0, 1024, 0, 768, -1 ,1);
	glMatrixMode(GL_MODELVIEW);
}

/*
 * Funcao usada na funcao callback para controlar as teclas comuns (1 Byte) do teclado
 */
void keyboard(unsigned char key, int x, int y){
    switch (key) { // key - variavel que possui valor ASCII da tecla precionada
        case ESC: exit(EXIT_SUCCESS); break; //encerra o programa com sucesso
    }
}

/*
 * Funcao usada na funcao callback para desenhar na tela
 */

void janelinha(int x, int y, int raio){
	glTranslatef(x, y, 0.0);
 	glColor3f(0, 0.8078, 0.8196);
 	glBegin(GL_TRIANGLE_FAN);
		float pi = 3.14159265358979323846;
 		int i;
 		GLfloat angulo;
 		int num_linhas = 100;
 		angulo = (2 * pi) / num_linhas;
 		
		for(i = 1; i <= num_linhas; i++){
  			glVertex2f(-raio*sin(i * angulo) , raio*cos(i * angulo));
		}
    glEnd();
}

void display(void){
	//Limpa o Buffer de Cores e reinicia a matriz
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();

//Casco do navio
	//Triangulo esquerdo
	glColor3f(0.588,0.3,0.0);
	glBegin(GL_TRIANGLES);
	 	glVertex2f(262, 50);
	 	glVertex2f(30, 250);
	 	glVertex2f(262, 250);
	glEnd();
	 
	 //Triangulo direito
	glColor3f(0.588,0.3,0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(762, 50);
		glVertex2f(994, 250);
		glVertex2f(762, 250);
	glEnd();
    
    //Retangulo do navio.
    glColor3f(0.688,0.4,0.0);
    glBegin(GL_QUADS);
    	glVertex2f(262, 50); //inferior esquerdo
    	glVertex2f(762, 50); //inferior direito
	 	glVertex2f(762, 250); //superior direito
	 	glVertex2f(262, 250); //superior esquerdo
 	glEnd();
	 
 	//Janelinhas
 	janelinha(352, 150, 50);
 	glLoadIdentity();
 	janelinha(502, 150, 50);
 	glLoadIdentity();
 	janelinha(652, 150, 50);
 	glLoadIdentity();
 	
 	
//Cabine do Navio
 	//Cabine do tripulante
 	glColor3f(0.588, 0.3, 0.0);
 	glBegin(GL_QUADS);
 		glVertex2f(412, 250); //inferior esquerdo
    	glVertex2f(612, 250); //inferior direito
	 	glVertex2f(612, 450); //superior direito
	 	glVertex2f(412, 450); //superior esquerdo
	glEnd();
	
	//Janela do tripulante
 	glColor3f(0, 0.8078, 0.8196);
 	glBegin(GL_QUADS);
 		glVertex2f(432, 270); //inferior esquerdo
    	glVertex2f(592, 270); //inferior direito
	 	glVertex2f(592, 430); //superior direito
	 	glVertex2f(432, 430); //superior esquerdo
	glEnd();
	
	
//Base traseira do navio
 	//Base baixa
 	glColor3f(0.588,0.3,0.0);
 	glBegin(GL_QUADS);
 		glVertex2f(652, 250); //inferior esquerdo
    	glVertex2f(852, 250); //inferior direito
	 	glVertex2f(852, 350); //superior direito
	 	glVertex2f(652, 350); //superior esquerdo
	glEnd();
	
	//Base alta
 	glColor3f(0.688,0.4,0.0);
 	glBegin(GL_QUADS);
 		glVertex2f(682, 350); //inferior esquerdo
    	glVertex2f(822, 350); //inferior direito
	 	glVertex2f(822, 450); //superior direito
	 	glVertex2f(682, 450); //superior esquerdo
	glEnd();

	
//Mastro
	glColor3f(0.588,0.3,0.0);
 	glBegin(GL_QUADS);
 		glVertex2f(352, 250); //inferior esquerdo
    	glVertex2f(382, 250); //inferior direito
	 	glVertex2f(382, 650); //superior direito
	 	glVertex2f(352, 650); //superior esquerdo
	glEnd();
	
	//Bandeira
	glColor3f(0.0,0.0,0.0);
 	glBegin(GL_QUADS);
 		glVertex2f(382, 520); //inferior esquerdo
    	glVertex2f(572, 520); //inferior direito
	 	glVertex2f(572, 640); //superior direito
	 	glVertex2f(382, 640); //superior esquerdo
	glEnd();
	
	//Vela
	glColor3f(1.0, 0.8431, 0);
	glBegin(GL_TRIANGLES);
		glVertex2f(352, 640);
		glVertex2f(352, 250);
		glVertex2f(90, 250);	
	glEnd();
	
glFlush(); // manda o OpenGl renderizar as primitivas

}