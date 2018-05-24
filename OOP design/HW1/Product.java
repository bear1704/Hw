package new_pos;
//
//20133222 박수찬
//설명 : 물품의 정보를 담당합니다. 물품의 정보는 바코드,이름,갯수,가격으로 구성됩니다. 바코드는 구분을 위한 임의의 코드입니다.

import java.io.Serializable;

public class Product implements Serializable{

	
	public Product(int barCode,String name,int amount, int price){
		
		this.barCode = barCode;
		this.name = name;
		this.amount = amount;
		this.price = price;
		
		
	}
	private int barCode;
	private int amount;
	private String name;
	private int price;
	
	
	public int getBarCode(){
		return barCode;
	}
	public int getAmount(){
		return amount;
	}
	public String getName(){
		return name;
	}
	public int getPrice(){
		return price;
	}
	
	
	public void setBarCode(int barCode){
		this.barCode = barCode;
	}
	public void setAmount(int amount){
		if(amount>=0){
		this.amount = amount;}
		else{
			System.out.println("재고는 0개 미만이 될 수 없습니다! 0개로 설정합니다." );
			this.amount = 0;
		}
	}
	public void setName(String name){
		this.name = name;
	}
	public void setPrice(int price){
		this.price = price;
	}
	
}
