// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#define MAX_SEQ 7
#define BUFF_SIZE ((MAX_SEQ + 1) / 2)

struct frame {
    int seq;
    int ack;
    char data;
};


void send_frame(struct frame *f, int frame_no, int frame_expected, char buffer[]) {
    f->seq = frame_no;
    f->ack = (frame_expected + MAX_SEQ) % (MAX_SEQ + 1);
    f->data = buffer[frame_no % BUFF_SIZE];
    printf("Frame sent: Seq=%d, Ack=%d, Data=%c\n", f->seq, f->ack, f->data);
}
int main() {
    int frame_exp;
    int next_frame_to_send = 0;
    int ack_expected = 0;
    int window_boundary = BUFF_SIZE;
    char outbuffer[BUFF_SIZE];
    char inbuffer[BUFF_SIZE];
    bool arrived[BUFF_SIZE] = { false };
    for (int i = 0; i < BUFF_SIZE; i++) {
        outbuffer[i] = 'A'+ i;
       
    }
   
    struct frame f;
   for (int i = 0; i < BUFF_SIZE; i++) {
        send_frame(&f, next_frame_to_send, ack_expected, outbuffer);
        next_frame_to_send = (next_frame_to_send + 1) % (MAX_SEQ + 1);
    }

    return 0;
}