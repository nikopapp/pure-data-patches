#include <m_pd.h>

typedef struct {
    t_object x_obj;
    t_float x_f1,x_f2;
} t_plus;

static t_class *plus_class;

static void *plus_new(t_floatarg f) {
    t_plus *x = (t_plus *)pd_new(plus_class);
    outlet_new(&x->x_obj, &s_float);
    floatinlet_new(&x->x_obj, &x->x_f2);
    x->x_f1 = 0;
    x->x_f2 = f;
    return (x);
}

static void plus_bang(t_plus *x) { outlet_float(x->x_obj.ob_outlet, x->x_f1 + x->x_f2); }

static void plus_float(t_plus *x, t_float f) {
    outlet_float(x->x_obj.ob_outlet, (x->x_f1 = f) + x->x_f2);
}

extern "C" void plus_setup(void) {
plus_class = class_new(gensym("plus"), (t_newmethod)plus_new, 0, sizeof(t_plus), CLASS_DEFAULT,
A_DEFFLOAT, 0);
    class_addbang(plus_class, plus_bang);
    class_addfloat(plus_class, (t_method)plus_float);
}
