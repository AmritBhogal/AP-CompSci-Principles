#ifndef _TURTLE_LAB_COMMON_
#define _TURTLE_LAB_COMMON_

#define ATTRIBUTE(name) __attribute__((name))

#define ON_EVENT(event)     SDL_Event (_ ## event ## _sdlevent);\
                            SDL_WaitEvent(&(_ ## event ## _sdlevent));\   
                            switch ((_ ## event ## _sdlevent).type)\
                                case (event):                                

 
#endif