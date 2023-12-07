void ps2_check(Ps2Core *ps2_p, GpoCore *led_p, SsegCore *sseg_p, GpiCore *sw_p) {
   int id;
   char ch;
   int player1point=0; //keyboard
   int player2point=0; //nexys4ddr
   int player1point_prev=0;
   int player2point_prev=0;
   //unsigned long last;

   int flipTimeSet = 850;
   int currTime;
   int win = 0;
   int checked = 0;

   sseg_p->set_dp(0x00);

   int num_array[8];

   	num_array[0] = 0;
   	num_array[1] = 0;
   	num_array[2] = 0;
   	num_array[3] = 0;
   	num_array[4] = 0;
   	num_array[5] = 0;
   	num_array[6] = 0;
   	num_array[7] = 0;

   	uart.disp("Ready to begin game!\n\r");
   	led_check(led_p, 16);

   	testingnumbers(sseg_p, num_array);

   //uart.disp("\n\rPS2 device (1-keyboard / 2-mouse): ");
   id = ps2_p->init();
   //uart.disp(id);
   //uart.disp("\n\r");

   do {
         if (ps2_p->get_kb_ch(&ch)) {
        	 player1point_prev = player1point;
			 player2point_prev = player2point;
        	 if((ch == 'a') && win == 0){ //A keyboard
        		 led_p->write(1,0);

        		 currTime=now_ms();
        		 while ( ((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==1) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }

        		 }

        		 led_p->write(0,0);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'b' && win == 0){ //B keyboard
        		 led_p->write(1,1);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet) ){
        			 int s=sw_p->read();
        			 if ((s==2) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,1);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'c' && win == 0){ //C keyboard
        		 led_p->write(1,2);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==4) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,2);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'd' && win == 0){ //D keyboard
        		 led_p->write(1,3);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==8) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,3);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'e' && win == 0){ //E keyboard
        		 led_p->write(1,4);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==16) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }


        		 led_p->write(0,4);

        		 if (checked == 0 ){
        			 player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'f' && win == 0){ //f keyboard
        		 led_p->write(1,5);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==32) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,5);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'g' && win == 0){ //g keyboard
        		 led_p->write(1,6);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==64) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,6);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'h' && win == 0){ //h keyboard
        		 led_p->write(1,7);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==128) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,7);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'i' && win == 0){ //h keyboard
        		 led_p->write(1,8);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==256) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }


        		 led_p->write(0,8);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'j' && win == 0){ //i keyboard
        		 led_p->write(1,9);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==512) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,9);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'k' && win == 0){ //j keyboard
        		 led_p->write(1,10);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==1024) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }


        		 led_p->write(0,10);

        		 if (checked == 0 ){
        		      player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'l' && win == 0){ //k keyboard
        		 led_p->write(1,11);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==2048) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,11);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'm' && win == 0){ //l keyboard
        		 led_p->write(1,12);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==4096) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,12);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'n' && win == 0){ //m keyboard
        		 led_p->write(1,13);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==8192) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }


        		 led_p->write(0,13);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'o' && win == 0){ //n keyboard
        		 led_p->write(1,14);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==16384) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,14);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }
        	 if(ch == 'p' && win == 0){ //n keyboard
        		 led_p->write(1,15);

        		 currTime=now_ms();
        		 while (((now_ms() - currTime) < flipTimeSet)){
        			 int s=sw_p->read();
        			 if ((s==32768) && (checked == 0)){
        				 player2point=player2point+100;
        				 checked = 1;
        				 break;
        			 }
        		 }

        		 led_p->write(0,15);

        		 if (checked == 0 ){
        		     player1point=player1point+100;
        		 }

        		 checked = 0;

        		 if((player1point > 900) || (player2point > 900)){
        			 win = 1;
        		 }

        	 }

        	 if(player1point_prev != player1point){
        		 num_array[6] = (player1point / 100) % 10;
        		 num_array[7] = player1point / 1000;

        	 }

        	 if(player2point_prev != player2point){
        		 num_array[2] = (player2point / 100) % 10;
        		 num_array[3] = player2point / 1000;
        	 }

        	 testingnumbers(sseg_p, num_array);

            uart.disp(" ");
            //last = now_ms();
         } // end get_kb_ch()
        // end id==2
   } while (win == 0);

   if (player1point > player2point){
	   num_array[7] = 1;
   }
   else {
	   num_array[3] = 1;
   }
   testingnumbers(sseg_p, num_array);
   sleep_ms(2000);

   uart.disp("Game over\n\r");
   led_check(led_p, 16);
   uart.disp(" ");
   //uart.disp("\n\rExit PS2 test \n\r");

}
