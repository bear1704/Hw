package new_pos;


//
//20133222 박수찬
//설명 : Pos기의 재고 관리를 담당하는 클래스입니다. 만약 저장된 정보가 있다면 저장된 정보를 불러오고, 없다면 생성자에 기본으로 지정된 물품을 가져옵니다.


import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;
public class Inventory implements Serializable{

	
	public Inventory(){
		arr.add(new Product(100001,"삼각김밥",30,1000));
		arr.add(new Product(100002,"사각김밥",40,1500));
		arr.add(new Product(100003,"아이스크림",100,1300));
		arr.add(new Product(100004,"샌드위치",30,2000));
		
	}
	public Inventory(ArrayList<Product> arr){
		this.arr = arr;
	}
	
	static Scanner sc = new Scanner(System.in);  
	ArrayList<Product> arr = new ArrayList<Product>();
	private String str;
	
	
	
	
	public void welcome(Worker w,Log l){
		
		
		System.out.println("------------");
		System.out.println("---재고 관리---");
		System.out.println("------------");
		
		System.out.println("[추가] 물품 재고 추가 " );
		System.out.println("[차감] 물품 재고 차감 " );
		System.out.println("[생성] 새로운 물품 항목 생성 " );
		System.out.println("[현황] 재고 현황 " );
		System.out.print("입력 :  " );
		str = sc.nextLine();
		
		switch(str){
			case "추가":
				addProduct(l);
				break;
			case "차감":
				subtractProduct(l);
				break;
			case "생성":
				if(w.getAdmin()){
					setProduct(l);
					System.out.println("정상적으로 생성되었습니다");
					sc.nextLine();
					sc.nextLine();
				}else{
					System.out.println("권한이 없습니다 !!");
					sc.nextLine();
					sc.nextLine();
				}
				
				break;
			case "현황":
				for(Product p: arr){
					show_product(p,arr.indexOf(p));
				}
				sc.nextLine();
				break;
		}
	
		
		
		
	}
	
	public void show_product(Product p,int i){ // i = 순서			
		System.out.println( i + ". " + p.getBarCode()+ " / " + p.getName() + " / " + p.getPrice() + "원 / " + p.getAmount() + "개 ");
	}
	public void setProduct(Log l){
		
		int barCode;
		String name;
		int amount;
		int price;
		
		
		System.out.println("물품 생성 페이지입니다 " );
		System.out.print("생성할 물품의 바코드를 기입해주세요  : " );
		barCode = sc.nextInt();
		System.out.print("생성할 물품의 이름을 기입해주세요 : " );
		name = sc.nextLine();
		name = sc.nextLine();
		System.out.print("생성할 물품의 가격을 기입해주세요 : ");
		price = sc.nextInt();
		System.out.print("생성할 물품의 수량을 기입해주세요 : " );
		amount = sc.nextInt();
		
		arr.add(new Product(barCode,name,amount,price));
		Calendar cal = Calendar.getInstance();
		SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
		String date = sdf.format(cal.getTime());
		l.setLog(date + " " +" 품목 "+ name + " 가 새로 생성되었습니다. 가격 : " + price +"원 ");
	}
	
	public void addProduct(Log l){
		
		
		
		
		System.out.println("재고 추가 페이지입니다 " );
		System.out.print("추가를 원하는 상품의 바코드나, 상품명을 입력해주세요 : " );
		String str = sc.nextLine();
		boolean match = false; // match는 해당하는 상품이 목록에 있는지 없는지를 확인하기 위해 만든 부울 변수입니다. 있으면 참값이 됩니다.
		
		
		try{
		int searchCode = Integer.parseInt(str);
		
			for(Product a:arr){
				if(a.getBarCode() == searchCode){
					System.out.print(a.getName() + " 의 재고를 몇 개 추가하시겠습니까? ");
					int amount = sc.nextInt();
					a.setAmount(a.getAmount() + amount);
					System.out.println(amount + " 개의 재고를 추가하여 총 " + a.getAmount() + " 개가 되었습니다. ");
					match = true;
					Calendar cal = Calendar.getInstance();
					SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
					String date = sdf.format(cal.getTime());
					l.setLog(date + " " + a.getName() + " 가 " + amount + " 개 입하되었습니다. ");
				}
			}
			if(match == false) {System.out.println(" 해당하는 상품이 없습니다 " );}
			
		}catch(NumberFormatException e){
			
			for(Product a:arr){
				if(a.getName().equals(str)){
					System.out.print(a.getName() + " 의 재고를 몇 개 추가하시겠습니까? ");
					int amount = sc.nextInt();
					a.setAmount(a.getAmount() + amount);
					System.out.println(amount + " 개의 재고를 추가하여 총 " + a.getAmount() + " 개가 되었습니다. ");
					match = true;
					Calendar cal = Calendar.getInstance();
					SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
					String date = sdf.format(cal.getTime());
					l.setLog(date + " " + a.getName() + " 가 " + amount + " 개 입하되었습니다. ");
				                           }
						      }
			if(match == false) {System.out.println(" 해당하는 상품이 없습니다 " );}
			
		
		}
		
		sc.nextLine();
	}
	
public void subtractProduct(Log l){
		
		
		
		
		System.out.println("재고 차감 페이지입니다 " );
		System.out.print("차감을 원하는 상품의 바코드나, 상품명을 입력해주세요 : " );
		String str = sc.nextLine();
		boolean match = false;
		
		
		try{
		int searchCode = Integer.parseInt(str);
		
			for(Product a:arr){
				if(a.getBarCode() == searchCode){
					System.out.print(a.getName() + " 의 재고를 몇 개 차감하시겠습니까? ");
					int amount = sc.nextInt();
					a.setAmount(a.getAmount() - amount);
					System.out.println(amount + " 개의 재고를 차감하여 총 " + a.getAmount() + " 개가 되었습니다. ");
					match = true;
					Calendar cal = Calendar.getInstance();
					SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
					String date = sdf.format(cal.getTime());
					l.setLog(date + " " + a.getName() + " 가 " + amount + " 개 차감되었습니다 ");
				}
			}
			if(match == false) {System.out.println(" 해당하는 상품이 없습니다 " );}
			
			sc.nextLine();
		}catch(NumberFormatException e){
			
			for(Product a:arr){
				if(a.getName().equals(str)){
					System.out.print(a.getName() + " 의 재고를 몇 개 차감하시겠습니까? ");
					int amount = sc.nextInt();
					a.setAmount(a.getAmount() - amount);
					System.out.println(amount + " 개의 재고를 차감하여 총 " + a.getAmount() + " 개가 되었습니다. ");
					
					match = true;
					Calendar cal = Calendar.getInstance();
					SimpleDateFormat sdf = new SimpleDateFormat("dd일HH시mm분");
					String date = sdf.format(cal.getTime());
					l.setLog(date + " " + a.getName() + " 가 " + amount + " 개 차감되었습니다. ");
				                           }
						      }
			if(match == false) {System.out.println(" 해당하는 상품이 없습니다 " );}
			
		
		}
		
		sc.nextLine();
	}
	
	public ArrayList<Product> getProduct(){
		return arr;
	}
	public void setProduct(ArrayList<Product> p){
		arr = p;
	}
	
}



