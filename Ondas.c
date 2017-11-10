#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
// imrpotar condiciones
  float L = 0.64;
  float c = 250.0;
  float dt = 0.00001;
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



  float *t_2 = malloc(129*sizeof(float));
  float *t_4 = malloc(129*sizeof(float));
  float *t_8 = malloc(129*sizeof(float));

  int n_time = 10000;
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



    if(j==256){
      for(i=0; i<129; i++){
        t_2[i] = fi_future[i];
      }
    }


    if(j==128){
      for(i=0; i<129; i++){
        t_4[i] = fi_future[i];
      }
    }


    if(j==64){
      for(i=0; i<129; i++){
        t_8[i] = fi_future[i];
      }
    }
  }



/*En la segunda parte del ejercicio deben repetir lo anterior pero ahora deben suponer que la
cuerda es perturbada periodicamente en uno de los extremos. Use una función sin((2πc/L)*t),
y tomando la amplitud de la cuerda como cero en t=0.*/



float *t2 = malloc(129*sizeof(float));
float *fi_past2 = malloc(129*sizeof(float));
float *fi_present2 = malloc(129*sizeof(float));
float *fi_future2 = malloc(129*sizeof(float));
float *l_cuerda2 = malloc(129*sizeof(float));
float *fi_initial2 = malloc(129*sizeof(float));

for(i=0;i<129;i++){
  fi_initial2[i]= 0.0;
}

/*
//imrprimir datos importados
for(i=0; i<129; i++){
  printf("%f %f \n",l_cuerda[i],fi_initial[i]);
}
*/
fi_future2[0] = 0.0;
fi_future2[128] = 0.0;
for (i=1; i<128; i++){
  fi_future2[i] = fi_initial2[i] + ((r*r)/2.0) * (fi_initial2[i+1] - 2.0 * fi_initial2[i] + fi_initial2[i-1]);
}


for(i=0; i<129; i++){
  fi_past2[i] = fi_initial2[i];
}
for(i=0; i<129; i++){
  fi_present2[i] = fi_future2[i];
}



float *t_2_2 = malloc(129*sizeof(float));
float *t_4_2 = malloc(129*sizeof(float));
float *t_8_2 = malloc(129*sizeof(float));

int n_time2 = 10000;
for (j=1; j<n_time2-1; j++){
  fi_future2[128] = sin(2*3.1415*c*j*dt/L);
  for (i=1; i<128;i++){
      fi_future2[i] = (2.0*(1.0-(r*r)))*fi_present2[i] - fi_past2[i] + (r*r)*(fi_present2[i+1] +  fi_present2[i-1]);
  }

  for (i=0; i<129; i++){
    fi_past2[i] = fi_present2[i];
  }
  for (i=0; i<129; i++){
    fi_present2[i] = fi_future2[i];
  }

  if(j==256){
    for(i=0; i<129; i++){
      t_2_2[i] = fi_future2[i];
    }
  }

  if(j==128){
    for(i=0; i<129; i++){
      t_4_2[i] = fi_future2[i];
    }
  }


  if(j==64){
    for(i=0; i<129; i++){
      t_8_2[i] = fi_future2[i];
    }
  }
}

printf("%f \n",r);
//guardar los datos
  FILE *in;
	in = fopen("datos1d.txt", "w");
	for (i =0; i<129; i++){
		fprintf(in," %f %f %f %f %f %f %f %f %f\n",l_cuerda[i], fi_initial[i],fi_present[i],t_2[i],t_4[i],t_8[i],t_2_2[i],t_4_2[i],t_8_2[i]);
  }

}
