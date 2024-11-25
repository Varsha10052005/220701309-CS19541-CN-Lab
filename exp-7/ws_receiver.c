#include <stdio.h>
#include <stdbool.h>
#define max 7
#define buff 4
struct frame{
    int seq;
    int ack;
    char data;
};
static bool between(int a, int b, int c){
     return ((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a));
}
void receive_frame(int f_no,int f_exp,char buf[],bool arr[]){
    struct frame f;
    int i=0;
    if (between(f_exp,f.seq,f_no) && (arr[f.seq % buff]==false)) {
         arr[f.seq % buff] = true;
         buf[f.seq % buff] = f.data;
    }
    for(i=0;i<buff;i++)
        printf("data:%c\n",buf[i]);
       
   
}
int main(){
  int frame_exp;
    int next_frame_to_send = 0;
    int ack_expected = 0;
    int window_boundary = buff;
    char outbuffer[buff];
    char inbuffer[buff];
    bool arrived[buff] = { false };
    for (int i = 0; i < buff; i++) {
        outbuffer[i] = 'A'+ i;
       
    }
   
   for (int i = 0; i < buff; i++) {
        receive_frame(next_frame_to_send, ack_expected, outbuffer,arrived);
        next_frame_to_send = (next_frame_to_send + 1) % (max+ 1);
    }

    return 0;
}