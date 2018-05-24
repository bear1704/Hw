package new_pos;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Scanner;

//
// 20133222 �ڼ���
//

public class Main {

	
	Log log = new Log(); 
	Worker worker = new Worker(); 
	Sell sell = new Sell();
	Scanner sc = new Scanner(System.in);
	Cash cash = new Cash();
	ArrayList<Product> p = new ArrayList<>();
	Inventory iv = new Inventory();
	String input;
	
	public static void main(String[] args){
		
		Main main = new Main();
		main.init();
		main.welcome();
		
		
	}

	public void init(){  //���� : ���α׷��� ����Ǹ� ���� ���� ����Ǵ� �޼ҵ��Դϴ�. ���� ����� �����Ͱ� �ִٸ� ��ü���� �� �����Ϳ� ���� �ʱ�ȭ��Ű��, ������ ���� ����ϴ�.
		File f = new File("save.sav");
		if(f.exists()){
			
			try{
				
			FileInputStream fis = new FileInputStream("save.sav");
			ObjectInputStream ois = new ObjectInputStream(fis);
			
			cash = (Cash) ois.readObject();
			p = (ArrayList<Product>) ois.readObject();
			log = (Log) ois.readObject();
			iv = (Inventory) ois.readObject();
			sell = (Sell) ois.readObject();
			worker = (Worker) ois.readObject();
			ois.close();
			}catch(Exception e){
				e.printStackTrace();
			}
			
			
		}
		
		
	}
	
	public void welcome(){  //���� : ���� ȭ�鿡�� �� �ൿ�� �� �� �ְ� �ȳ����� ���� �޼ҵ��Դϴ�. ���� �۾��� ��ġ�� �ٽ� ����� ���ƿ��� �ǹǷ�,
							//     ���ƿ� �� ���� �����͸� �����ؼ� ������ �� �ְ� �մϴ�.
		
		//���� ����
		
		try{
			FileOutputStream fos = new FileOutputStream("save.sav");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			
			oos.writeObject(cash);
			oos.writeObject(iv.getProduct());
			oos.writeObject(log);
			oos.writeObject(iv);

			oos.writeObject(sell);
			oos.writeObject(worker);
			oos.close();
			
		}catch(Exception e){}
		
		
		//-----------------
		System.out.println("-----------------------------------");
		System.out.println("              POS                  ");
		System.out.println("-----------------------------------");
		System.out.println("���� �ٹ��ڴ� " + worker.getName() + " �Դϴ�. \n");
		System.out.println("���� �ܰ� :  " + cash.getCash());
		System.out.println("[�Ǹ�] ��ǰ �Ǹ�");
		System.out.println("[����] ��� ����");
		System.out.println("[����] �ٹ��� ����");
		System.out.println("[�α�] ������ ���");
		System.out.print("�Է� : ");
		
		String str = sc.nextLine();
		
		switch(str){  
		case "����":
			System.out.print("������� �̸��� �Է��� �ּ��� : ");
			input = sc.nextLine();
			worker.setWorker(input,log);
			welcome();
			break;
		case "����":
			iv.welcome(worker,log);
			welcome();
			break;
		case "�Ǹ�":
			sell.welcome(iv.getProduct(),cash,log);
			welcome();
			break;
		case "�α�": 
			log.welcome(worker);
			welcome();
			break;
			
		
		}
	    
	}
	
}

