#include<avr/io.h>
#include<util/delay.h>
#define bin_val_DDR DDRD
#define bin_val_PORT PORTD

#define SSD_DDR DDRA
#define SSD_PORT PORTA
#define opm_DDR DDRB
#define opm_PIN PINB

#define SSD_DIG PORTC
#define SSD_DIG_DDR DDRC

#define DIG0 0
#define DIG1 1
#define DIG2 2
#define DIG3 3

void init_ssd(void);
void ssd_split(void); //proto

unsigned char SSD[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char ssd_dig[]={0,0};
int m;

int main(void){
   
   init_ssd();

     while(1){
	     for(m=0;m<=15;m++){
		     bin_val_PORT=m;
			 ssd_split();
			 _delay_ms(20);
			 
			 	    
					     if (PINB & (1<<DIG0)){         // get PB0
			                 while(PINB & (1<<DIG0)){
								 SSD_DIG= 1<<DIG0;
								 SSD_PORT=SSD[ssd_dig[0]];
								 _delay_ms(20);
								 
								 SSD_DIG= 1<<DIG1;
								 SSD_PORT=SSD[ssd_dig[1]];
								 _delay_ms(20);
				 
		            }
			 }
		 
	 } }
}
void ssd_split(){
    	ssd_dig[0]=m/10;
		ssd_dig[1]=m%10; 
}
void init_ssd(void){
     bin_val_DDR |=(1<<DIG0 |1<<DIG1 |1<<DIG2 |1<<DIG3);  //1 ,,output
     bin_val_PORT &= ~(1<<DIG0 |1<<DIG1 |1<<DIG2 |1<<DIG3);  //0 ,,input
	 SSD_DIG_DDR |= 1<<DIG0 | 1<<DIG1;            //ssd
	 opm_DDR=0<<DIG0;
     SSD_DDR=0xff;              
     SSD_PORT=0x00;             
}	 


