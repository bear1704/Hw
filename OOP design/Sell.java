package new_pos;

//
//20133222 �ڼ���
//
//���� : ������ �Ǹ��ϴ� ����Դϴ�. ���ڵ� Ȥ�� ��ǰ�̸��� �Է��ؼ� �Ǹ��� ��, ����� ������ ��� ���Ը�ŭ�� ������ cash ��ü�� �߰��մϴ�.
//     Arraylist cart�� ������ ��Ƽ� �� ���� ��ٱ��� �����Դϴ�. �Ǹ�Ȯ���� �ϸ� ������ϴ�(clear())

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;
public class Sell implements Serializable{

	
	
	static Scanner sc = new Scanner(System.in);
	ArrayList<Product> cart = new ArrayList<>();
	
	
	
	public void welcome(ArrayList<Product> p,Cash cash,Log l){
		
		
		
		
	
		
		select(p,cash,l);

			
		
		
		
		
	}
	public int select(ArrayList<Product> p,Cash cash,Log l){
		boolean match = false;
		
		System.out.println("��ǰ �Ǹ� �������Դϴ�. ���Ͻô� ��ǰ�� Ȥ�� ���ڵ带 �Է��� �ּ���.\n �Ǹ��Ͻ÷��� '�Ǹ�'�� �Է��� �ּ���\n �����Ͻ÷��� '����'�� �Է��� �ּ���");
		System.out.print("�Է� : ");
		String str = sc.nextLine();
		
		try{
		int searchCode = Integer.parseInt(str);
		
		for(Product a:p){
				if(a.getBarCode() == searchCode){
					System.out.println(a.getName() + " / " + a.getPrice() +  "��"); // īƮ �߰�
					cart.add(a);
					match = true;
				}
		}
					if(match == false){System.out.println("�ش��ϴ� ��ǰ�� �����ϴ� ");}
					sc.nextLine();
		
		  }catch(NumberFormatException e){
			  
			  for(Product a:p){
			   if(a.getName().equals(str)){
					  System.out.println(a.getName() + " / " + a.getPrice() +  "��  �߰���" ); 
						cart.add(a);
						match = true;
				  }
					  
			  }if(str.equals("����")){
					cart.clear();
				 return 0;
			  }
			  else if(str.equals("�Ǹ�")){ 
				  sellCart(p,cash,l);
			  }
			  else if(match == false){System.out.println("�ش��ϴ� ��ǰ�� �����ϴ� ");}
			//	sc.nextLine();
			  	
			  
		                                 }
		
	sc.nextLine();
	select(p,cash,l);
	
	return 0;
	
	}
	
	public void sellCart(ArrayList<Product> p,Cash cash,Log l){
		
		
		for(Product temp:cart){
			  System.out.println("��ǰ��  : " + temp.getName() + "���� : " + temp.getPrice());
			  
			  if(temp.getAmount() - 1 >= 0){
			  cash.setCash(temp.getPrice());
			  temp.setAmount(temp.getAmount() - 1);
			 
			  }
			  else{System.out.println(temp.getName() + " �� ��� �����ϴ�! ");	}
				  	
			  
				Calendar cal = Calendar.getInstance();
				SimpleDateFormat sdf = new SimpleDateFormat("dd��HH��mm��");
				String date = sdf.format(cal.getTime());
			  l.setLog(date + " " + temp.getName() + "�� �Ǹŵ�  / ���� : " + temp.getPrice());
			  
		  }
		
		System.out.println("---- �ǸŵǾ����ϴ�. ----" + " ���� �ܾ� : " + cash.getCash() + "��");
		cart.clear();

	}
	
	
	
	
	
}
