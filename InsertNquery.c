import java.sql.*;
import java.util.*;
class InsertNQuery{
public static void main(String args[]) throws Exception{
Connection con=null;
PreparedStatement psmt=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
 psmt=con.prepareStatement("insert into aitscse2a values(?,?,?,?,?)");
Scanner sin=new Scanner(System.in);
System.out.println("Enter n record to insert..");
int n=sin.nextInt();
int i=0;
while(i<n){
System.out.println("Enter record:"+i);
System.out.println("Enter roll:");
String sroll=sin.next();
System.out.println("Enter name:");
String sname=sin.next();
System.out.println("Enter branch:");
String sbranch=sin.next();
System.out.println("Enter address:");
String saddress=sin.next();
System.out.println("Enter dream company:");
String sdcompany=sin.next();
psmt.setString(1,sroll);
 psmt.setString(2,sname);
psmt.setString(3,sbranch);
psmt.setString(4,saddress);
psmt.setString(5,sdcompany);
int x=psmt.executeUpdate();
if(x>0)
 
 System.out.println(x+"rows inserted"+"\n");
 i++;
 
}
}
catch(ClassNotFoundException | SQLException e){
e.printStackTrace();
}
finally{
psmt.close();
con.close();
}
}
}
