package new_pos;

import java.io.Serializable;
//
//20133222 �ڼ���
// POS���� ������ �ٷ�� Ŭ�����Դϴ�

public class Cash implements Serializable{

	private int cash;

	
	public void print_imcome(){
		
		System.out.println("== -- == -- == -- == -- == -- == -- == -- == -- == --");
		System.out.println("���� ���� : " + cash );
		System.out.println("== -- == -- == -- == -- == -- == -- == -- == -- == --");
		
	
		
	}

	public void setCash(int income){cash+=income;}

	public int getCash(){return cash;}
	
}
