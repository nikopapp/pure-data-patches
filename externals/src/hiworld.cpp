#include "m_pd.h"


static t_class *hiworld_class;
 
typedef struct {
    t_object x_obj;
} t_hiworld;

static void *hiworld_new(void){
  t_hiworld *x = (t_hiworld *)pd_new(hiworld_class);
  return (x);
}


static void hiworld_bang(t_hiworld *x){
 post("Hi world!");
}

extern "C" void hiworld_setup(void){
 hiworld_class = class_new(gensym("hiworld"),(t_newmethod)hiworld_new, 0, sizeof(t_hiworld),CLASS_DEFAULT,A_DEFFLOAT,0);
 class_addbang(hiworld_class, hiworld_bang);
}
