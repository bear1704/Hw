package new_pos;

//
//20133222 박수찬
//
//설명 : 물건을 판매하는 기능입니다. 바코드 혹은 상품이름을 입력해서 판매한 뒤, 재고의 갯수를 깎고 수입만큼의 현금을 cash 객체에 추가합니다.
//     Arraylist cart는 결제를 모아서 할 때의 장바구니 개념입니다. 판매확정을 하면 비워집니다(clear())

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
		
		System.out.println("상품 판매 페이지입니다. 원하시는 상품명 혹은 바코드를 입력해 주세요.\n 판매하시려면 '판매'를 입력해 주세요\n 종료하시려면 '종료'를 입력해 주세요");
		System.out.print("입력 : ");
		String str = sc.nextLine();
		
		try{
		int searchCode = Integer.parseInt(str);
		
		for(Product a:p){
				if(a.getBarCode() == searchCode){
					System.out.println(a.getName() + " / " + a.getPrice() +  "원"); // 카트 추가
					cart.add(a);
					match = true;
				}
		}
					if(match == false){System.out.println("해당하는 상품이 없습니다 ");}
					sc.nextLine();
		
		  }catch(NumberFormatException e){
			  
			  for(Product a:p){
			   if(a.getName().equals(str)){
					  System.out.println(a.getName() + " / " + a.getPrice() +  "원  추가됨" ); 
						cart.add(a);
						match = true;
				  }
					  
			  }if(str.equals("종료")){
					cart.clear();
				 return 0;
			  }
			  else if(str.equals("판매")){ 
				  sellCart(p,cash,l);
			  }
			  else if(match == false){System.out.println("해당하는 상품이 없습니다 ");}
			//	sc.nextLine();
			  	
			  
		                                 }
		
	sc.nextLine();
	select(p,cash,l);
	
	return 0;
	
	}
	
	public void sellCart(ArrayList<Product> p,Cash cash,Log l){
		
		
		for(Product temp:cart){
			  System.out.println("물품명  : " + temp.getName() + "가격 : " + temp.getPrice());
			  
			  if(temp.getAmount() - 1 >= 0){
			  cash.setCash(temp.getPrice());
			  temp.setAmount(temp.getAmount() - 1);
			 
			  }
			  else{System.out.println(temp.getName() + " 의 재고가 없습니다! ");	}
				  	
			  
				Calendar cal = Calendar.getInstance();
				SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
				String date = sdf.format(cal.getTime());
			  l.setLog(date + " " + temp.getName() + "이 판매됨  / 가격 : " + temp.getPrice());
			  
		  }
		
		System.out.println("---- 판매되었습니다. ----" + " 현재 잔액 : " + cash.getCash() + "원");
		cart.clear();

	}
	
	
	
	
	
}
