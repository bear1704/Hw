package new_pos;
//
//20133222 �ڼ���
//���� : ��ǰ�� ������ ����մϴ�. ��ǰ�� ������ ���ڵ�,�̸�,����,�������� �����˴ϴ�. ���ڵ�� ������ ���� ������ �ڵ��Դϴ�.

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
			System.out.println("���� 0�� �̸��� �� �� �����ϴ�! 0���� �����մϴ�." );
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
