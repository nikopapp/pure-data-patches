#include "m_pd.h"

static t_class *midilabel_class;

typedef struct _midilabel
{
    t_object x_obj;
    t_float i_note;
} t_midilabel;
char *lookup[107] = {
    "A0",
    "A#0",
    "B0",
    "C1",
    "C#1",
    "D1",
    "D#1",
    "E1",
    "F1",
    "F#1",
    "G1",
    "G#1",
    "A1",
    "A#1",
    "B1",
    "C2",
    "C#2",
    "D2",
    "D#2",
    "E2",
    "F2",
    "F#2",
    "G2",
    "G#2",
    "A2",
    "A#2",
    "B2",
    "C3",
    "C#3",
    "D3",
    "D#3",
    "E3",
    "F3",
    "F#3",
    "G3",
    "G#3",
    "A3",
    "A#3",
    "B3",
    "C4",
    "C#4",
    "D4",
    "D#4",
    "E4",
    "F4",
    "F#4",
    "G4",
    "G#4",
    "A4",
    "A#4",
    "B4",
    "C5",
    "C#5",
    "D5",
    "D#5",
    "E5",
    "F5",
    "F#5",
    "G5",
    "G#5",
    "A5",
    "A#5",
    "B5",
    "C6",
    "C#6",
    "D6",
    "D#6",
    "E6",
    "F6",
    "F#6",
    "G6",
    "G#6",
    "A6",
    "A#6",
    "B6",
    "C7",
    "C#7",
    "D7",
    "D#7",
    "E7",
    "F7",
    "F#7",
    "G7",
    "G#7",
    "A7",
    "A#7",
    "B7",
    "C8",
    "C#8",
    "D8",
    "D#8",
    "E8",
    "F8",
    "F#8",
    "G8",
    "G#8",
    "A8",
    "A#8",
    "B8",
    "C9",
    "C#9",
    "D9",
    "D#9",
    "E9",
    "F9",
    "F#9",
    "G9"};
int lookup_offset = 21;
void midilabel_bang(t_midilabel *x)
{

    char *out;

    int note = (int)x->i_note;
    if (note < lookup_offset || note > 127)
    {
        out = "OOR";
    }
    else
    {
        out = lookup[note - lookup_offset];
    }
    outlet_symbol(x->x_obj.ob_outlet, gensym(out));
    post(out);
}

void midilabel_float(t_midilabel *x, t_float f)
{
    x->i_note = f;
    midilabel_bang(x);
}

void *midilabel_new(t_floatarg f)
{
    t_midilabel *x = (t_midilabel *)pd_new(midilabel_class);
    /* create a new outlet for floating-point values */
    outlet_new(&x->x_obj, &s_float);
    /* set the counter value to the given argument */
    x->i_note = f;

    return (void *)x;
}

void midilabel_setup(void)
{
    midilabel_class = class_new(gensym("midilabel"),
                                (t_newmethod)midilabel_new,
                                0, sizeof(t_midilabel),
                                CLASS_DEFAULT,
                                A_DEFFLOAT, 0);
    class_addbang(midilabel_class, midilabel_bang);
    class_addfloat(midilabel_class, (t_method)midilabel_float);
}
