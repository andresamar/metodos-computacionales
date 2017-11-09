#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
// imrpotar condiciones
  float L = 0.64;
  float c = 250.0;
  float dt = 0.000005;
  int i;
  int j;
  float *t = malloc(129*sizeof(float));
  float *fi_past = malloc(129*sizeof(float));
  float *fi_present = malloc(129*sizeof(float));
  float *fi_future = malloc(129*sizeof(float));
  float *l_cuerda = malloc(129*sizeof(float));
  float *fi_initial = malloc(129*sizeof(float));
  //leer archivo
  FILE *cond  = fopen("cond_ini_cuerda.dat", "r");
  //cantidad de datos en listas = 129 por lista

  //importar archivo a celdas
  for (i = 0; i < 129; i++){
    fscanf(cond,"%f %f \n", &l_cuerda[i], &fi_initial[i]);
  }
  fclose(cond);

/*
  //imrprimir datos importados
  for(i=0; i<129; i++){
    printf("%f %f \n",l_cuerda[i],fi_initial[i]);
  }
  */
  float dx = l_cuerda[1] - l_cuerda[0];
  float r = c * dt / dx;
  fi_future[0] = 0.0;
  fi_future[128] = 0.0;
  for (i=1; i<128; i++){
    fi_future[i] = fi_initial[i] + ((r*r)/2.0) * (fi_initial[i+1] - 2.0 * fi_initial[i] + fi_initial[i-1]);
  }


  for(i=0; i<129; i++){
    fi_past[i] = fi_initial[i];
  }
  for(i=0; i<129; i++){
    fi_present[i] = fi_future[i];
  }





  int n_time = 200000;
  for (j=0; j<n_time; j++){
    for (i=1; i<128;i++){
        fi_future[i] = (2.0*(1.0-(r*r)))*fi_present[i] - fi_past[i] + (r*r)*(fi_present[i+1] +  fi_present[i-1]);
    }



    for (i=0; i<129; i++){
      fi_past[i] = fi_present[i];
    }
    for (i=0; i<129; i++){
      fi_present[i] = fi_future[i];
    }
  }

  //printf("%f \n",r);
    //guardar los datos
  FILE *in;
	in = fopen("datos1d.txt", "w");
	for (i =0; i<129; i++){
		fprintf(in," %f %f %f \n",l_cuerda[i], fi_initial[i],fi_present[i]);
  }
  for (i=0;i<129;i++){
    printf(" %f \n",fi_present[i]);
  }
}






//  for(i=0; i<129; i++){
//    printf("%lf \n",x[i]);
//  }
