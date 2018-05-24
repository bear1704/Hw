package new_pos;

import java.io.Serializable;
//
//20133222 박수찬
// POS기의 현금을 다루는 클래스입니다

public class Cash implements Serializable{

	private int cash;

	
	public void print_imcome(){
		
		System.out.println("== -- == -- == -- == -- == -- == -- == -- == -- == --");
		System.out.println("현금 수입 : " + cash );
		System.out.println("== -- == -- == -- == -- == -- == -- == -- == -- == --");
		
	
		
	}

	public void setCash(int income){cash+=income;}

	public int getCash(){return cash;}
	
}
