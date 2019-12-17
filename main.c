//Bibliotecas
#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 


/// Requisitos recomendados para correr el juego: 40 de ram 320 mhz

//Función global para detección de colisiones
#define checar_colision(x1,y1,w1,h1,x2,y2,w2,h2) (!( ((x1)>=(x2)+(w2)) || ((x2)>=(x1)+(w1)) || ((y1)>=(y2)+(h2)) || ((y2)>=(y1)+(h1)) ))

//Constantes globales
    //Resolución de la pantalla de juego
#define ANCHURA_VENTANA 800
#define ALTURA_VENTANA 600


#define ROJO makecol(255,0,0)
#define BLANCO makecol(255,255,255)
#define AZUL makecol(0,0,255)
#define NEGRO makecol(0,0,0)
#define VERDE makecol(0,255,0)
#define VERDEF makecol(51,102,51)
#define AMARILLO makecol(255,255,0)
#define CYAN makecol(0,255,255)
#define MAGENTA makecol(255,0,255)
#define GRIS makecol(192,192,192)


const int u_p_s = 1;
volatile int boton_cerrar = FALSE;
volatile int fin_juego = FALSE;
volatile int ticks=0;
PALETTE paleta;   
BITMAP *buffer;
FONT *chiller;
DATAFILE *recursos;

void ticker(){/////////////////////////
      ticks++;
   }
   END_OF_FUNCTION(ticker)
 


void cerrar_juego(void){/////////////////
	 boton_cerrar = TRUE;
	 fin_juego = TRUE;
	 
}END_OF_FUNCTION(cerrar_juego);


void desinvocar_allegro(){
/*Fin de procesos para graficar*/
release_screen();
allegro_exit();
printf("\nAllegro ha sido satisfactoriamente desinvocado"); 
}END_OF_FUNCTION(desinvocar_allegro);

void invocar_allegro(){   /////////////////////////// 
allegro_init();
printf("\nMotor de Allegro Inicializado");
srand( time( NULL ) );
//set_color_depth(32);
set_color_depth(32);
set_gfx_mode(GFX_AUTODETECT,ANCHURA_VENTANA,ALTURA_VENTANA,0,0);
printf("\nModo grafico establecido");
LOCK_FUNCTION(cerrar_juego);
set_close_button_callback(cerrar_juego);
set_window_title("Aztlan Oseloyotl");
set_palette(default_palette);
printf("\nPaleta de colores, funcion de cerrado y titulo de ventana establecidos");
solid_mode();
printf("\nModo de muestreo de colores establecido");
install_keyboard();
install_timer();
clear_to_color(screen,makecol(0,0,0));
printf("\nPantalla a utilizar clarificada (clear to color)");
buffer = create_bitmap(ANCHURA_VENTANA, ALTURA_VENTANA);
printf("\nBuffer grafico inicializado");
LOCK_VARIABLE(ticks);
LOCK_FUNCTION(ticker);
install_int(ticker,10);
install_int_ex(ticker, SECS_TO_TIMER(u_p_s));
printf("\nEntorno grafico cargado correctamente");
printf("\nCargando recursos...");
recursos = load_datafile("recursos.dat");
if(!recursos){
allegro_message("No se ha encontrado el archivo \"recursos.dat\". Intenta instalar de nuevo el juego o comentale al creador!\n");
printf("\nFallo al cargar los recursos!!! D:");}
else
printf("\nRecursos Bien cargados");
chiller = (FONT *)recursos[1].dat;
if (!chiller){
              allegro_message("Fallo al crear la fuente de escritura D: \n Comentale esto al creador!\n");
	 printf("\nNo se ha cargado la fuente!");}
else
printf("\nFuente bien cargada, po perro!");	 
}END_OF_FUNCTION(invocar_allegro);

void presentacion(int tickz){/////////////
     if(tickz>3)
     textprintf_ex(buffer, chiller, 150,100, VERDE, -1, "Una produccion de:");
     if(tickz>5)
     draw_sprite(buffer, recursos[0].dat,172,130);
     if(tickz>9)
     textprintf_ex(buffer, chiller, 200,500, ROJO, -1, "Visita http://technologies.dtcsrni.tk");
     if(tickz>11)
     textprintf_ex(buffer, chiller, 220,520, AZUL, -1, "El hogar de la tecnologia DtcSrni");
     if(tickz>13)
     textprintf_ex(buffer, chiller, 300,550, CYAN, -1, "(:D)");
     }END_OF_FUNCTION(presentacion); 

void pantalla_principal( int roll, int alt){///////////////
     
     draw_sprite(buffer, recursos[2].dat,150,50);//logojuego
     draw_sprite(buffer, recursos[roll].dat,255,alt);///Shitty tinga called seleccionador


     textprintf_ex(buffer, chiller, 270,480, BLANCO, -1, "|Crear Nueva Partida|");
     textprintf_ex(buffer, chiller, 270,510, BLANCO, -1, " |Cargar una Partida| ");
     textprintf_ex(buffer, chiller, 270,540, BLANCO, -1, "     |Creditos|      ");
           
}END_OF_FUNCTION(pantalla_principal); 

void cinemato(){
     clear_bitmap(buffer);
     clear_keybuf();
     printf("\nDibuja primer cuadro de cinematicas");
     if(!keypressed()){ 
           draw_sprite(buffer, recursos[6].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           if(!keypressed())
           rest(1000);
           clear_bitmap(buffer);
           }
     if(!keypressed()){        
           draw_sprite(buffer, recursos[7].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           rest(15000);
           clear_bitmap(buffer);
           }
      if(!keypressed()){     
           draw_sprite(buffer, recursos[8].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           rest(14000);
           clear_bitmap(buffer);
           }
       if(!keypressed()){    
           draw_sprite(buffer, recursos[9].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           rest(15000);
           clear_bitmap(buffer);
           }
       if(!keypressed()){    
           draw_sprite(buffer, recursos[10].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           rest(15000);
           clear_bitmap(buffer);
           }
       if(!keypressed()){    
           draw_sprite(buffer, recursos[11].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           rest(14000);
           clear_bitmap(buffer);
           }
       if(!keypressed()){    
           draw_sprite(buffer, recursos[12].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           rest(16000);
           clear_bitmap(buffer);
           }
       if(!keypressed()){    
           draw_sprite(buffer, recursos[13].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           rest(6000);
           clear_bitmap(buffer);
           }
           }END_OF_FUNCTION(cinemato);
  void creditos(){
       do{
       clear_bitmap(buffer);
           draw_sprite(buffer, recursos[17].dat,0,0);
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
           }while(!keypressed());
       
       
                }END_OF_FUNCTION(creditos);
  void muerto_fin(int puntos, int tipo){
   int temp=0;
  if(tipo==1){ 
   clear_keybuf();
        do{
            if(puntos<0){
            if(temp!=puntos)
            temp--;}
            if(puntos>0){
            if(temp!=puntos)
            temp++;}
            
            
       clear_bitmap(buffer);
           draw_sprite(buffer, recursos[24].dat,0,0);
         textprintf_ex(buffer, chiller,260,160, BLANCO, -1, "---TE HAN MATADO!!--- (D:)");
         textprintf_ex(buffer, chiller,180,260, BLANCO, -1, "Al final, los espanoles resultaron ser mas rudos que tu, morro...");
         textprintf_ex(buffer, chiller,300,310, AMARILLO, -1, "|Puntuacion total: %i |",temp);
         if(temp==puntos) 
         textprintf_ex(buffer, chiller,200,550, GRIS, -1, "Pulsa cualquier tecla para regresar a la pantalla principal");   
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
          rest(100);
          if(temp!=puntos)
          clear_keybuf(); 
           }while(!keypressed());}
     if(tipo==2){   
        clear_keybuf();
        do{
            if(puntos<0){
            if(temp!=puntos)
            temp--;}
            if(puntos>0){
            if(temp!=puntos)
            temp++;}
            
            
       clear_bitmap(buffer);
           draw_sprite(buffer, recursos[24].dat,0,0);
         textprintf_ex(buffer, chiller,260,160, BLANCO, -1, "---HAS MUERTO!!--- (D:)");
         textprintf_ex(buffer, chiller,200,260, BLANCO, -1, "Felicidades! Has servido como alimento para animales! ");
         textprintf_ex(buffer, chiller,150,280, BLANCO, -1, "Aunque eso no le agrada a las morras y no es util al imperio Azteca");
         textprintf_ex(buffer, chiller,300,310, AMARILLO, -1, "|Puntuacion total: %i |",temp);
         if(temp==puntos) 
         textprintf_ex(buffer, chiller,200,550, GRIS, -1, "Pulsa cualquier tecla para regresar a la pantalla principal");   
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
          rest(80);
          if(temp!=puntos)
          clear_keybuf(); 
           }while(!keypressed());            
                                  }
           clear_keybuf(); 
       }END_OF_FUNCTION(muerto_fin); 
  
  void victoria_fin(int puntos){
       int temp=0;
   clear_keybuf();
        do{
            if(puntos<0){
            if(temp!=puntos)
            temp--;}
            if(puntos>0){
            if(temp!=puntos)
            temp++;}
            
            
       clear_bitmap(buffer);
           draw_sprite(buffer, recursos[26].dat,0,0);
         textprintf_ex(buffer, chiller,200,160, VERDE, -1, "---HAS DERROTADO AL PODEROSO SOLDADO ESPAÑOL!!--- (:D)");
         textprintf_ex(buffer, chiller,100,260, BLANCO, -1, "\"Y al final, Cuauhpopoca se ha alzado por sobre el experimentado soldado espanol.\"");
         textprintf_ex(buffer, chiller,10,280, BLANCO, -1, "Eres un heroe entre los Aztecas, todo un perro entre los compadres, y todo un papi entre las nenas");
         textprintf_ex(buffer, chiller,300,310, AMARILLO, -1, "|Puntuacion total: %i |",temp);
         if(temp==puntos) 
         textprintf_ex(buffer, chiller,200,550, GRIS, -1, "Pulsa cualquier tecla para regresar a la pantalla principal");   
           blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);
          rest(70);
          if(temp!=puntos)
          clear_keybuf(); 
           }while(!keypressed());

       }END_OF_FUNCTION(victoria_fin);     
                    
                
  int calc_movy( int *caidaa, int *movyy, int *activado, int *sprite, int *activo, int *movyt){
      
        static int fin=0;
        if(*activo==0){
                      *movyt=*movyy;
                      *activo=1;
                      }     
       if(*caidaa==1){
                      *sprite=2;
         if(*movyy>=*movyt-200 && *activado==0)             
       *movyy=*movyy-20;
          if(*movyy==*movyt-200)
          *activado=1;
        if(*activado==1){  
         if(*movyy<*movyt)
       *movyy=*movyy+20;}
                    }
       
       if(*movyy==*movyt && *caidaa ==1){
        *caidaa=0;
        fin=1;
        *activo=0;
        *activado=0;
        *sprite=0;
        }
        
       return fin;
       }END_OF_FUNCTION(calc_movy); 
       
     static  int random(int min,int max){

    int range = max - min;
    return rand() % range + min;

}END_OF_FUNCTION(random); 
                      
              
 void disparar(int *disparador,int *dif, int *signon, int *movxbb, int *movybb, int *movxgg, int *granada, int movxx, int movyy, int *coldowngg, int *coldownbb, int *colisionn, int *colisionn2, int *vida, int *rotate, int *puntos){
      static int tempo;
    static  int pos=0;
 
      if(*disparador==1){  ///            
      *movxbb=735;
      *movybb=510;
   if(*coldowngg <= 0 && *coldownbb <=0){ 
      pos = random(1,8);
      *signon = random(1,3);}
      
      
      
     if(*colisionn2!=1){ 
      if(pos==7)  
      *granada=1;
      
      }
      else{
        if(*coldowngg>0){
        draw_sprite(buffer, recursos[23].dat,*movxgg,580);
      *coldowngg=*coldowngg-1;}
        else{
             
        *disparador=0;
        *colisionn2=0;
        }
      }
      
     if(*colisionn !=1){ 
      if(pos==1)
      *dif=0;
      if(pos==2)
      *dif=1;
      if(pos==3)
      *dif=2;
      if(pos==4)
      *dif=3;
      if(pos==5)
      *dif=4;
      if(pos==6)
      *dif=5;
      if(*signon==1)
      *signon=-1;
      if(*signon==2)
      *signon=1;
      *disparador=0;
      }
      else{
     if(*coldownbb>0)
      *coldownbb=*coldownbb-1;
      else{
          
      *colisionn=0;
      if(pos==1)
      *dif=0;
      if(pos==2)
      *dif=1;
      if(pos==3)
      *dif=2;
      if(pos==4)
      *dif=3;
      if(pos==5)
      *dif=4;
      if(pos==6)
      *dif=5;
      if(*signon==1)
      *signon=-1;
      if(*signon==2)
      *signon=1;
      *disparador=0;
          }
      }
      
     if(coldownbb>0){ 
      if(*granada!=1){
           *movxgg=900;
           }
          else{
               if(*movxgg==900)
               *movxgg=725;     
               if(*movxgg>0){
             *movxgg=*movxgg-8;
             if(*rotate>-256)
             *rotate=*rotate-16;
             else
             *rotate=0;  
      //draw_sprite(buffer, recursos[21].dat,*movxgg,580);
      rotate_sprite(buffer, recursos[21].dat,*movxgg,580, *rotate<<16);
      printf("rotate= %i", *rotate);
      tempo = checar_colision(movxx,movyy,50,95,*movxgg,580,20,20); 
      if(tempo==1){
      draw_sprite(buffer, recursos[23].dat,*movxgg,580);
      *granada=0;
      *coldowngg=1;
      *colisionn2=1;
      *vida=*vida-20;
      *puntos=*puntos-25;
                  }
                            }                 
             }
             }
      //draw_sprite(buffer, recursos[20].dat,*movxbb,*movybb);
     }///
     else{
        
        if(*granada!=1){
           *movxgg=900;
           }
          else{
               if(*movxgg==900)
               *movxgg=725;     
               if(*movxgg>0){
             *movxgg=*movxgg-8;  
      //draw_sprite(buffer, recursos[21].dat,*movxgg,580);
      if(*rotate>-256)
             *rotate=*rotate-16;
             else
             *rotate=0;  
      rotate_sprite(buffer, recursos[21].dat,*movxgg,580, *rotate<<16);
      printf("rotate= %i", *rotate);       
      tempo = checar_colision(movxx,movyy,50,95,*movxgg,580,20,20); 
      if(tempo==1){
      draw_sprite(buffer, recursos[23].dat,*movxgg,580);
      *granada=0;
      *coldowngg=1;
      *colisionn2=1;
      *vida=*vida-20;
      *puntos=*puntos-25;
                  }
                            }                 
             }
             
      if(*movxbb>0){
              
      *movybb=(*movybb+(*signon*(*dif)));
      *movxbb=*movxbb-20;   
      draw_sprite(buffer, recursos[20].dat,*movxbb,*movybb);
      tempo = checar_colision(movxx,movyy,50,95,*movxbb,*movybb,15,10);
      if(tempo==1){
      *colisionn=1; 
      *disparador=1;
      *vida=*vida-10;
      *coldownbb=30;
      *puntos=*puntos-5; 
                  }
          }     
          else{
          *disparador=1;
          
          }
          
      }       
}END_OF_FUNCTION(disparar);

void salto_arco(int radio, int rbasex, int rbasey, int *x, int *y, int *sentido, int *caida, int *actividad){
               if(*sentido==0){
               *x=rbasex-radio;
               *y=rbasey; 
               *sentido=1;
               *actividad=0;
               }
               if(*sentido==2 ){
                 if(*caida==0){
                    if(*x>=rbasex){
                       *actividad=1;                         
                      *x=*x-8;
                      *y=*y-10;}
                      else
                      *caida=1;
                              }    
                  if(*caida==1){
                    if(*x>=(rbasex-radio)){
                      *x=*x-8;
                      *y=*y+10;} 
                      else{
                      *sentido=0;
                      *caida=0;
                      *actividad=0;     
                           }                           
                              }              
                             }
               if(*sentido==1){
                  if(*caida==0){              
                    if(*x<rbasex){
                      *actividad=1;                                     
                      *x=*x+8;
                      *y=*y-10;}
                      else
                      *caida=1;
                              }    
                  if(*caida==1){
                    if(*x<(rbasex+radio)){
                      *x=*x+8;
                      *y=*y+10;} 
                      else{
                      *sentido=2;
                      *caida=0;
                      *actividad=0;    
                           }                           
                              }            
                               }
                                                           
               }END_OF_FUNCTION(salto_arco);
               
              

int main()
{
srand (time(NULL));
/*Mensaje*/ printf("\nEsta pantalla sirve solo para fines de depuraci\xA2n y testeo,\n puedes minimizarla si quieres, ser\xA0 borrada cuando la versi\xA2n definitiva\n sea lanzada");
printf("\n\nCargando entorno grafico...");    
invocar_allegro();///////////////////
rest(1500);	 
int frames=0;
static int temp7=0, fin=FALSE, subirflag=0, tempa4=0, spriteroll=0,switcher=0,flipiedra=0,sobrearbol=0, colPant1=0,piedratx=0, coltronco=0, downestado=1, piedratirada=0, caerflag=0,piedractiva=0, piedraty=0, piedrax=300, piedray=487, colpiedra=0, colpiedra1=0, colpiedra2=0, colPant2=0, movx=0, movy=492, ranax=380, ranay=600, troncox=620, troncoy=45,tronco2x=0, tronco2y=500, troncotemp=0, angulotronco, troncoarriba=1, sentido1, caida1, actividad1=1, cocodrilox=370, cocodriloy=468, cocodrilox2=370, cocodriloy2=468, piranax=270,piranay=590, retornococodrilo=0, retornococodrilo2=0, retornopirana=0, deshabilitado=0, temp=0, tempa=0,temp2=0, temp3=0, temp4=0, temp5=0, limitePant=0, activoo=0, alt =480, iniciado=0,victoria=0, temp1=0,vida_enemigo=150, enemigo_coli=0, estado=0,movytt=0, flip=0, row=0, caida=0, activado=0, activador=1, movxb=735, movyb=510, vitalidad=100, diferencia, signo, angulo=0, movxg, granadaa=0, coldowng=0, coldownb=0, colision=0, colision2=0, abajo=0, muerto=0, ganar=0, puntuacion=0, derrota=0;
int FPS=0; 
volatile int mov=0;
  printf("\nInicia loop con presentacion\n"); 

 
do{
                         

///All the shit mosto go between here
//////////////////////////////////////////////////////////////////////////////////////////////////////    
   if(iniciado==0){ ///Comprueba si el juego ya ha pasado de la pantalla principal o no
  
//if(ticks<17)
//presentacion(ticks);

//if(ticks>=18){ 
 if(ticks>=1){                         
 textprintf_ex(buffer, chiller,700,570, GRIS, -1, "V1.1 beta"); 


if(keypressed()==TRUE){      
temp=(readkey() >> 8);
switch(temp){
 case KEY_DOWN:
      if(alt<530)
      alt=alt+30;
         
pantalla_principal(3,alt);

clear_keybuf();
printf("\nTecla presionada abajo, alt=%i", alt);/// ///////////////////////////////////
break;
case KEY_UP:
     if(alt>480)
     alt=alt-30;
printf("\nTecla presionada arriba, alt=%i", alt);/// ///////////////////////////////////
pantalla_principal(3,alt);
clear_keybuf();
break;
case KEY_ENTER:
     printf("\nTecla Enter presionada");
     if(alt==480){
     estado=1;printf("\nEstado=1");
     iniciado=1;}
     if(alt==510){
     estado=2;  printf("\nEstado=2");           
     iniciado=1;
    }
     if(alt==540){
     estado=3; printf("\nEstado=3");            
     iniciado=1;}
break;     
}
}
else{
pantalla_principal(5,alt);
}
}

spriteroll++;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
if(iniciado==1){                                                      printf("\nIniciado=1");
        if(estado==1){printf("\n Inicia cinematicas");
            cinemato(1);
            clear_keybuf();
            printf("\nFinaliza cinematicas");
            muerto=0;
            victoria=0;
            vitalidad=100;
            vida_enemigo=150;
            iniciado=2;
            //estado=1;
                     }   
        if(estado==2){
                      clear_keybuf();
                      do{
                          draw_sprite(buffer, recursos[25].dat,0,0);                                
                          blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);                     
                               }while(!keypressed());
                              iniciado=0;
                               clear_keybuf(); 
                      }                
        if(estado==3){                                      printf("\nInicia presentacion de creditos");
                      creditos();
                      printf("\nFinaliza presentacion de creditos");
                      clear_keybuf();
                      iniciado=0;                    
                      }                            
              }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(iniciado==2){
               
      ///////////////////Nivel 1////////////////////// 
      draw_sprite(buffer, recursos[18].dat,limitePant,0);///pintando escenario
      /////Iniciando rutinas de movimiento de teclado
      
if(caida==1)
        calc_movy(&caida,&movy,&activado, &spriteroll, &activoo, &movytt); 
        


      if(keypressed()== TRUE){             
         row++;
                                               
         mov=(readkey()>> 8);
         
         switch(mov){
                     case KEY_RIGHT:
                          if(movx<((limitePant+800-20)-69))
                          movx=movx+10;
                          if(spriteroll!=2){
                          spriteroll=1;
                         if(row<=2)
                     draw_sprite(buffer, recursos[14].dat,movx,movy);
                        else{
                         if(row>2 && row<=4 && spriteroll!=2)
                     draw_sprite(buffer, recursos[15].dat,movx,movy);}
                          flip=0;          
                          tempa=frames;}
                          else{
                               
                     draw_sprite(buffer, recursos[16].dat,movx,movy);
                        
                               }
                          
                         break;
                     case KEY_LEFT:
                          if(movx>(limitePant+20))
                          movx=movx-10;
                          if(spriteroll!=2){
                          spriteroll=1;
                          if(row<=2)
                     draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);
                         else{
                          if(row>2 && row<=4 && spriteroll!=2)
                     draw_sprite_h_flip(buffer, recursos[15].dat,movx,movy);}
                          flip=1;
                          tempa=frames;}
                          else{
                              draw_sprite_h_flip(buffer, recursos[16].dat,movx,movy); 
                               
                               }
                         break;
                     case KEY_UP:
                         if(caida!=1 && abajo !=1){
                         spriteroll=2;
                          calc_movy(&caida,&movy,&activado, &spriteroll, &activoo, &movytt);
                          
                          caida=1;
                          } 
                      draw_sprite(buffer, recursos[16].dat,movx,movy);
                          break;  
                     case KEY_X:
                          vitalidad=100;
                          break;
                     case KEY_DOWN:
                         if(caida!=1){             
                                                
                          movy=530;
                          abajo=1;
                          } 
                       draw_sprite(buffer, recursos[22].dat,movx,movy); 
                       break;          
                   }
                   
                   if(row>=4)
                   row=0;
                            }
         else{
             if(abajo==1 && caida!=1){
                      
             abajo=0;
             movy=492;
             
             }
               
               if(spriteroll==2){
               if(flip==0)
                   draw_sprite(buffer, recursos[16].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[16].dat,movx,movy);
                   }
                  else{ 
               if(spriteroll==1){
                      if(frames!=tempa+5){
                      if(flip==0)
                   draw_sprite(buffer, recursos[15].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[15].dat,movx,movy);      
                                       }
                                       else{                                            
                                   spriteroll=0;
                      if(flip==0)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);
                                                    }                  
                                      }  
               else{
                      if(flip==0)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);                   
                                      }
                                                        
                    }                  
}           
          /////////finalizan rutinas de movimiento de personaje

         
          
//Enemigo 1, colifion con enemigo, daño a enemigo y vida del enemigo efpañol
if(enemigo_coli>0){
       if((enemigo_coli%2) == 0)          
   draw_sprite_h_flip(buffer, recursos[19].dat,731,492);
   enemigo_coli--;
   }
  else
    draw_sprite_h_flip(buffer, recursos[19].dat,731,492);
   if(enemigo_coli<=0){
   temp = checar_colision(movx,movy,50,95,731,492,65,108);
   if(temp==1){
  puntuacion=puntuacion+10;
  vida_enemigo=vida_enemigo-20;
  enemigo_coli=100;
  }
}
rectfill(buffer, 380, 93, 550, 115, CYAN); 
textprintf_ex(buffer, chiller, 400,96, ROJO, -1, "ENEMIGO EFPANOL");
rectfill(buffer, 500,120,(vida_enemigo+500),140,AMARILLO); 
rect(buffer, 500,120,650,140,AZUL); 
if(vida_enemigo<=0)
victoria=1;    
 
if(victoria!=1) 
   disparar(&activador,&diferencia, &signo, &movxb, &movyb, &movxg, &granadaa, movx, movy, &coldowng, &coldownb, &colision, &colision2, &vitalidad, &angulo, &puntuacion);


   
////////Dibujando barra de vida
rectfill(buffer, 20, 45, 110, 60, CYAN);
textprintf_ex(buffer, chiller, 20,43, ROJO, -1, "VITALIDAD");
rectfill(buffer, 0,60,vitalidad,80,ROJO); 
rect(buffer, 0,60,100,80,VERDE);
//////Dibujando puntuacion
textprintf_ex(buffer, chiller,500,43, CYAN, -1, "PUNTUACION: %i", puntuacion);


////Si vida llega a cero o menos, muere
if(vitalidad<=0){
muerto=1;                                 
                 } 
                 if(muerto==1){
              muerto=0;
              victoria=0;
muerto_fin(puntuacion,1);
iniciado=0;
clear_keybuf();
vitalidad=100;
vida_enemigo=150;
movx=0; 
puntuacion=0;
movy=492;
}
if(victoria==1){
                muerto=0;
                victoria=0;
                puntuacion=puntuacion+100;

victoria_fin(puntuacion);
clear_keybuf();
vitalidad=100;
vida_enemigo=150;
movx=0;
puntuacion=0;
iniciado=3; 
movy=392;
                                        
}
  }

////////////////////////////////////////////////////////////////////////////////////////////////Finaliza nivel 1
/////////////////////////////////////////////////////////////////////////////Inicia Nivel 2///////////////////////////////
if(iniciado==3){

               
      ///////////////////Nivel 2////////////////////// 
      draw_sprite(buffer, recursos[27].dat,limitePant,0);///pintando escenario
      if(limitePant==-800){// Si pantalla 2
      //ColPant = Colisión alguna en la pantalla que se está mostrando
//Pintando árbol        
draw_sprite(buffer, recursos[34].dat,360,190); }
      
      if(temp2==0){
      movy=movy-100;
      temp2=1;
      }
     if(caerflag==1){
                     deshabilitado=1;                     
          if(movy<392)           
            movy=movy+10;
           else{
          caerflag=0; 
          deshabilitado=0;
          }          
                     }
      
      
if(caida==1)
        calc_movy(&caida,&movy,&activado, &spriteroll, &activoo, &movytt); 
        

     if(deshabilitado!=1) 
     switcher=keypressed();
     else
     switcher=FALSE;
      if(switcher== TRUE){
      
      
      
             
         row++;
         
                                              
         mov=(readkey()>> 8);
        
/*        downestado = GetKeyState(VK_DOWN);
        if(downestado==-127 || downestado==-128)
          mov=KEY_DOWN;*/
          
         
         switch(mov){
                     case KEY_RIGHT:
                          
                          if(movx<800-69){
                           if(subirflag!=1)
                          movx=movx+15;}
                          else{
                          if(limitePant!=-3200){     
                          limitePant=limitePant-800;
                          movx=5;
                              }
                          }            
                          
                          if(spriteroll!=2){
                          spriteroll=1;
                         if(row<=2)
                         if(subirflag!=1)
                     draw_sprite(buffer, recursos[14].dat,movx,movy);
                     else
                     draw_sprite(buffer, recursos[35].dat,movx,movy);
                        else{
                         if(row>2 && row<=4 && spriteroll!=2){
                               if(subirflag!=1)   
                     draw_sprite(buffer, recursos[15].dat,movx,movy);
                     else
                     draw_sprite(buffer, recursos[35].dat,movx,movy);
                     }}
                          flip=0;          
                          tempa=frames;}
                          else{
                               
                     draw_sprite(buffer, recursos[16].dat,movx,movy);                      
                               } 
                               
                               if(movx>=205&&movx<=315&&caida!=1&&limitePant==0){
                                       deshabilitado=1;  
                                       clear_keybuf();                                        
                               }
                               if(movx>=489&&limitePant==-800){
                                        
                                       deshabilitado=1;                                        
                                       clear_keybuf();                                        
                               }
                             
                                                              
                         break;
                     case KEY_LEFT:
                           
                          if(limitePant==-800 && movy<250 && movx<320){
                                              caerflag=1;
                                 printf("\nDeberia caer ahora"); 
                                 }
                          
                          if(movx>(0)){
                          if(subirflag!=1)
                          movx=movx-15;}
                          else{
                          if(limitePant!=0){
                          limitePant=limitePant+800; 
                          movx=731; }   
                          }
                          if(spriteroll!=2){
                          spriteroll=1;
                          if(row<=2){
                                     if(subirflag!=1)
                     draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);
                     else
                     draw_sprite_h_flip(buffer, recursos[35].dat,movx,movy);
                     }
                         else{
                          if(row>2 && row<=4 && spriteroll!=2){
                                   if(subirflag!=1)
                     draw_sprite_h_flip(buffer, recursos[15].dat,movx,movy);
                     else
                     draw_sprite_h_flip(buffer, recursos[35].dat,movx,movy);
                     }
                     }
                          flip=1;
                          tempa=frames;}
                          else{
                               if(subirflag!=1)
                              draw_sprite_h_flip(buffer, recursos[16].dat,movx,movy); 
                               
                               }
                               
                               if(movx>=205&&movx<=315&&caida!=1&&limitePant==0){
                                       deshabilitado=1; 
                                       clear_keybuf();                                         
                               }
                               if(movx>=485&&caida!=1&&limitePant==-800&&movy>450){
                                       deshabilitado=1;  
                                       clear_keybuf();                                        
                               }
                               
                               
                              
                               break;
                     case KEY_UP:
                          if(movx>=390&& movx<=500 && limitePant==-800 && movy<=392 && sobrearbol!=1)
                           subirflag=1;
                           
                          if(deshabilitado!=1 && subirflag!=1){
                         if(caida!=1 && abajo !=1){
                         spriteroll=2;
                          calc_movy(&caida,&movy,&activado, &spriteroll, &activoo, &movytt);
                          caida=1;
                                                 }  
                          }

                          if(subirflag==1){
                           if(movy>200)     {           
                            movy=movy-10;
                            draw_sprite(buffer, recursos[35].dat,movx,movy);  }
                           if(movy<=200){
                                  sobrearbol=1;       
                           subirflag=0;
                           draw_sprite(buffer, recursos[16].dat,movx,movy); }            
                                           
                          }
                          else
                          draw_sprite(buffer, recursos[16].dat,movx,movy);
                          
                      
                          break;  
                     case KEY_X:
                          vitalidad=100;
                          break;
                     case KEY_P:
                          if(colpiedra!=0 && piedratirada!=1){
                          piedratirada=1;
                          if(flip==1)
                          flipiedra=1;
                          else
                          flipiedra=2;
                          }
                          
                          if(spriteroll==2){
               if(flip==0)
                   draw_sprite(buffer, recursos[16].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[16].dat,movx,movy);
                   }
                  else{ 
               if(spriteroll==1){
                      if(frames!=tempa+5){
                      if(flip==0)
                   draw_sprite(buffer, recursos[15].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[15].dat,movx,movy);      
                                       }
                                       else{                                            
                                   spriteroll=0;
                      if(flip==0&& downestado!=-127 && downestado!=-128)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1&& downestado!=-127 && downestado!=-128)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);
                                                    }                  
                                      }  
               else{
                      if(flip==0&& downestado!=-127 && downestado!=-128)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1&& downestado!=-127 && downestado!=-128)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);                   
                                      }
                                                        
                    }
                          
                          break;
                          
                     case KEY_DOWN:
                         if(caida!=1 && subirflag!=1 && sobrearbol!=1){                                                           
                          movy=430;
                          abajo=1;
                         
                          }
                       if(subirflag==1 || sobrearbol==1){
                          if(movy<392) {
                          subirflag=1;             
                          movy=movy+10;
                          
                          }
                          else
                          if(movy>=392){
                          sobrearbol=0;                
                          subirflag=0; }
                          draw_sprite(buffer, recursos[22].dat,movx,movy);             
                       }
                        else   
                       draw_sprite(buffer, recursos[22].dat,movx,movy); 
                       break;
                        
                     default:
                     if(subirflag==1)
               draw_sprite(buffer, recursos[36].dat,movx,movy);
               
                        if(spriteroll==2 && subirflag==0){
               if(flip==0)
                   draw_sprite(buffer, recursos[16].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[16].dat,movx,movy);
                   }
                  else{ 
               if(spriteroll==1 && subirflag==0){
                      if(frames!=tempa+5){
                      if(flip==0)
                   draw_sprite(buffer, recursos[15].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[15].dat,movx,movy);      
                                       }
                                       else{                                            
                                   spriteroll=0;
                      if(flip==0 && subirflag==0 && downestado!=-127 && downestado!=-128)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1 && subirflag==0)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);
                                                    }                  
                                      }  
               else{
                      if(flip==0&& downestado!=-127 && downestado!=-128)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1&& downestado!=-127 && downestado!=-128)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);                   
                                      }
                                                        
                    }
                       
                       break;                  
                   }
                   
         
                    
                   
                   if(row>=4)
                   row=0;
                            }
                                                
         else{          
             if(subirflag==1)
               draw_sprite(buffer, recursos[36].dat,movx,movy); 
                                 
             if(abajo==1 && caida!=1){
                      
             abajo=0;
             movy=392;
             
             }
             if(movx>=205&&movx<=315&&movy>=392&&limitePant==0){
                              if(movy<=600){
                              deshabilitado=1;
                               movy=movy+10;}
                               else{
                                muerto=1;
                                puntuacion=puntuacion-25;
                                deshabilitado=0;
                                mov=0;
                               clear_keybuf();
                               }
                               }
             if(movx>=489&&limitePant==-800){
                                                  
                              if(movy<=600 && coltronco==0){
             
                              deshabilitado=1;
                              movy=movy+10;}
                                             
                                             else
                               if(movy<=600 && coltronco!=0){
                                  deshabilitado=0;          
                                            }                             
                               else{
                                    printf("\nColision tronco: %i, Movy: %i",coltronco, movy);
                                muerto=1;
                                puntuacion=puntuacion-25;
                                deshabilitado=0;
                                mov=0;
                               clear_keybuf();
                               }
                               }                  
                               
                              
               
               if(spriteroll==2 && subirflag==0){
               if(flip==0)
                   draw_sprite(buffer, recursos[16].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[16].dat,movx,movy);
                   }
                  else{ 
               if(spriteroll==1 && subirflag==0){
                      if(frames!=tempa+5){
                      if(flip==0)
                   draw_sprite(buffer, recursos[15].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[15].dat,movx,movy);      
                                       }
                                       else{                                            
                                   spriteroll=0;
                      if(flip==0)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);
                                                    }                  
                                      }  
               else{
                      if(flip==0 && subirflag==0)
                   draw_sprite(buffer, recursos[14].dat,movx,movy);    
                      if(flip==1 && subirflag==0)
                   draw_sprite_h_flip(buffer, recursos[14].dat,movx,movy);                   
                                      }
                                                        
                    }                  
}           
          /////////finalizan rutinas de movimiento de personaje
          
          ///Rutinas de comportamiento de entidades en pantalla 1
          if(limitePant==0){
//Rutinas de comportamiento de Cocodrilo
if(retornococodrilo==0){
    if(temp3==0){
draw_sprite(buffer, recursos[28].dat,cocodrilox,cocodriloy);
temp3=1;
                }
    else{
draw_sprite(buffer, recursos[29].dat,cocodrilox,cocodriloy);         
temp3=0;         
         } 
                       } 
if(retornococodrilo==1){
    if(temp3==0){
draw_sprite_h_flip(buffer, recursos[28].dat,cocodrilox,cocodriloy);
temp3=1;
                }
    else{
draw_sprite_h_flip(buffer, recursos[29].dat,cocodrilox,cocodriloy);         
temp3=0;         
         } 
                       } 
                                                          
if(retornococodrilo==0){
      if(cocodrilox<=720)                  
  cocodrilox=cocodrilox+3;
      else
    retornococodrilo=1;                            
                        }
if(retornococodrilo==1){
      if(cocodrilox>=370)
  cocodrilox=cocodrilox-3;
     else
   retornococodrilo=0;      
                       }                                             
colPant1=colPant1+(checar_colision(movx,movy,35,88,cocodrilox,cocodriloy,60,25));
   
//Rutinas de movimiento de Piraña
     
if(retornopirana==0)
draw_sprite(buffer, recursos[30].dat,piranax,piranay);
if(retornopirana==1)
draw_sprite_v_flip(buffer, recursos[30].dat,piranax,piranay);
         
if(retornopirana==0){
      if(piranay>280)                  
  piranay=piranay-10;
      else
    retornopirana=1;                            
                        }
if(retornopirana==1){
      if(piranay<=600)
  piranay=piranay+5;
     else
   retornopirana=0;      
                       } 
colPant1=colPant1+(checar_colision(movx,movy,40,88,piranax,piranay,25,60));

//Rutinas de movimiento de rana
if(actividad1==1)
salto_arco(180, 550, 465, &ranax, &ranay, &sentido1, &caida1, &actividad1);


if(actividad1==0){
      if(temp4==0)
      temp4=ticks;
if(ticks>=temp4+2){                                 
salto_arco(180, 550, 465, &ranax, &ranay, &sentido1, &caida1, &actividad1);
    temp4=0;
                }
}


if(sentido1==1||sentido1==0){
if(actividad1==0)                             
draw_sprite(buffer, recursos[31].dat,ranax,ranay);
else
draw_sprite(buffer, recursos[32].dat,ranax,ranay);
}
if(sentido1==2){
if(actividad1==0)                             
draw_sprite_h_flip(buffer, recursos[31].dat,ranax,ranay);
else
draw_sprite_h_flip(buffer, recursos[32].dat,ranax,ranay);
}
colPant1=colPant1+(checar_colision(movx,movy,40,88,ranax,ranay,35,35));

if(colPant1!=0){
      puntuacion=puntuacion-25;          
      muerto=1; }         
  }
  
  
if(limitePant==-800){//                    pantalla 2 y árbol 
   
    if(retornococodrilo2==0){
    if(temp3==0){
draw_sprite(buffer, recursos[28].dat,cocodrilox2,cocodriloy2);
temp3=1;
                }
    else{
draw_sprite(buffer, recursos[29].dat,cocodrilox2,cocodriloy2);         
temp3=0;         
         } 
                       } 
if(retornococodrilo2==1){
    if(temp3==0){
draw_sprite_h_flip(buffer, recursos[28].dat,cocodrilox2,cocodriloy2);
temp3=1;
                }
    else{
draw_sprite_h_flip(buffer, recursos[29].dat,cocodrilox2,cocodriloy2);         
temp3=0;         
         } 
                       } 
                                                          
if(retornococodrilo2==0){
      if(cocodrilox2<=400)    //-230              
  cocodrilox2=cocodrilox2+3;
      else
    retornococodrilo2=1;                            
                        }
if(retornococodrilo2==1){
      if(cocodrilox2>=140)
  cocodrilox2=cocodrilox2-3;
     else
   retornococodrilo2=0;      
                       }  
colPant2=colPant2+(checar_colision(movx,movy,30,88,cocodrilox2,cocodriloy2,60,25));  
                    
//Iniciando rutinas de comportamiento de piedra
if(colpiedra==0)
draw_sprite(buffer, recursos[33].dat,piedrax,piedray);                  
colpiedra=colpiedra+(checar_colision(movx,movy,69,108,piedrax,piedray,20,15));                      
if(colpiedra!=0){
circlefill(buffer, 320, 20, 13, VERDE);    
draw_sprite(buffer, recursos[33].dat,310,10);
textprintf_ex(buffer, chiller,317,35, VERDE, -1, "P");

if(colpiedra1!=0){//se revisa si la piedra colisionó con el árbol, si sí, entonces remueve la piedra, like you removed me from your life H
piedratirada=0;
if(piedraty<615){
piedraty=piedraty+20;
draw_sprite(buffer, recursos[33].dat,piedratx,piedraty);}
else
colpiedra1=0;
}

if(piedratirada==1){
if(piedractiva!=1){
 piedraty=movy+30;                   
 piedratx=movx+20;}
draw_sprite(buffer, recursos[33].dat,piedratx,piedraty);
if(piedratx<=815 && piedratx >=-15){
 if(flipiedra==1){
piedratx=piedratx-30;
piedractiva=1;
}
if(flipiedra==2){
piedratx=piedratx+30;
piedractiva=1;          
              }
colpiedra1=colpiedra1+(checar_colision(piedratx,piedraty,20,15,troncox,troncoy,165,42));
if(colpiedra1!=0)
colpiedra2=colpiedra2+1;
                 }
else{
piedractiva=0;
piedratirada=0;
flipiedra=0;
}
                   }                                                  
                } 
                                                                                
//Rutinas de comportamiento del tronco 
if(troncoarriba==1){
line(buffer, 700, 0, troncox+83, troncoy, VERDEF);   //linea de la que penderá el tronco, like my heart hangs off your blind will "Jsick"
line(buffer, 702, 0, troncox+85, troncoy+2, VERDEF);}
else
{
line(buffer, 700, 0, 700,20, VERDEF);  
line(buffer, 702, 0,702, 20, VERDEF);    
}
    // tronco y las diferentes posiciones que puede tomar
if(colpiedra2==0)
angulotronco=24;    
if(colpiedra2==1)
angulotronco=15;
if(colpiedra2==2)
angulotronco=0;
if(colpiedra2>2){
if(troncoy<535){
troncoy=troncoy+20;  }
else
troncoarriba=0;               
                  }
if(troncoarriba==0){                  
if(troncox<800&&troncotemp!=1 && troncoarriba==0) {
troncox=troncox+5;
if(coltronco!=0)
movx=movx+5;
}
else{
troncotemp=1;
if(troncox>505){ 
 troncox=troncox-5;
 if(coltronco!=0)
movx=movx-5;
 }
 else
  troncotemp=0;
}                  
               }
rotate_sprite(buffer, recursos[37].dat,troncox,troncoy, itofix(angulotronco));
if(troncoarriba==1){ 
if(troncox<632&&troncotemp!=1) {
troncox=troncox+1;
}
else{
troncotemp=1;
if(troncox>608){ 
 troncox=troncox-1;}
 else
  troncotemp=0;
}
}
if(troncoy>=535)
coltronco=checar_colision(movx,movy,60,90,troncox,troncoy,160,40); ///Colision con tronco y personaje        







// rutina de colision general con enemigos               
     if(colPant2!=0){
                     rest(1000);
      puntuacion=puntuacion-25;          
      muerto=1; }           
                   }
                   
                   
if(limitePant==-1600){  //pantalla 3
if(temp7==0){
    movy=392;
    temp7=1;                
             }
draw_sprite(buffer, recursos[37].dat,tronco2x,tronco2y);   
coltronco=checar_colision(movx,movy,60,90,tronco2x,tronco2y,160,40); ///Colision con tronco y personaje                        

       if(movx<193&&movy<=580&&coltronco!=0){
          if(movy<610){  
            deshabilitado=1;
            movy=movy+10;}
                else{
              deshabilitado=0;
              muerto=1;
                     }  
                        }                          
if(tronco2x<500) {
tronco2x=tronco2x+2;
tronco2y=tronco2y+1;
if(coltronco!=0){
movx=movx+5;
movy=movy+1;}
 
}
  }     
                   
                   
                  
  if(muerto==1){
   muerto_fin(puntuacion,2);
   rest(300);                             
   iniciado=0;
   clear_keybuf();
   movx=0; 
   movy=392;
   colPant1=0;
   colPant2=0;
   subirflag=0;
   colpiedra=0;
   muerto=0;
   piedratirada=0;
   troncox=620; 
   troncoy=45;
   troncoarriba=1;
   deshabilitado=0;
   limitePant=0;
   iniciado=0;
   vitalidad=100;
   vida_enemigo=150;
   caida=0;
   caerflag=0;
   colpiedra2=0;
   coltronco=0;
   
   
   
   puntuacion=0;
                }
}//////////////////////////////////////////////////////////////////////finaliza
                
if(ticks!=0)
FPS=frames/(ticks); 
textprintf_ex(buffer, font, 10,10, CYAN, -1, "Ticks:%i",ticks);
textprintf_ex(buffer, font, 10,20, CYAN, -1, "Frames:%i",frames);
textprintf_ex(buffer, font, 10,30, VERDE, -1, "FPS:%i",FPS);
frames++;

blit(buffer,screen, 0,0,0,0,ANCHURA_VENTANA, ALTURA_VENTANA);


clear_bitmap(buffer); 

/*And now the final frame 
Love is a losing game (H yo a hooker, but i swear i loved u) */

rest(26);
}while(!fin_juego);


desinvocar_allegro();//////////////
printf("\nCerrando Aplicaci\xA2n");
return 0;    
}END_OF_MAIN();




