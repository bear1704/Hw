package new_pos;
//
//20133222 �ڼ���
//

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class Worker implements Serializable{ // ����: �ٹ��ڴ� �ٲ��� �ʴ´� �����߽��ϴ�. �� �ٹ��ڴ� �̸���, ������ ���Ѹ��� ���� ������ ��ü�Դϴ�.
											//      ������ ������ �α� Ȯ���̳� ��ǰ ���� �� Ư���� ������ �ʿ��մϴ�.
	
	public Worker(){
		
		name.put(0, "ö��");
		name.put(1, "����");
		name.put(2, "�μ�");
		name.put(3, "��ö");
		name.put(4, "����");
		
		worker = name.get(0);
		master = false;
	}
	
	 
	private String worker;
	HashMap<Integer,String> name = new HashMap<>();
	private boolean master;
	

	
	public String getName(){
		return worker;
	}
	public boolean getAdmin(){
		return master;
	}
	
	public String setWorker(String name,Log l){
		
		if(this.name.containsValue(name))
		{
			if(name.equals("����")){
				System.out.println(name + " ���� ����Ǿ����ϴ�");
				
				Calendar cal = Calendar.getInstance();
				SimpleDateFormat sdf = new SimpleDateFormat("dd��HH��mm��");
				String date = sdf.format(cal.getTime());
				l.setLog(date + " " + "�ٹ��ڰ� " + worker + " ���� " + name + " ���� ����Ǿ����ϴ�.");
				master = true;
				worker = name;
				
				return name;
			}else{
				System.out.println(name + " ���� ����Ǿ����ϴ�");
				
				Calendar cal = Calendar.getInstance();
				SimpleDateFormat sdf = new SimpleDateFormat("dd��HH��mm��");
				String date = sdf.format(cal.getTime());
				l.setLog(date + " " + "�ٹ��ڰ� " + worker + " ���� " + name + " ���� ����Ǿ����ϴ�.");
				master = false;
				worker = name;
				return name;
			}
		
		}else{
			System.out.println("�׷� �ٹ��ڴ� �������� �ʽ��ϴ�");
			return worker; 
		}
	}

}
