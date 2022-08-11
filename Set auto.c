import java.sql.*;
class SetAuto{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
con.setAutoCommit(false);
stmt=con.createStatement();
String uQuery="update aitscse2a set address='kurnool' where Rollno='502'";
int i=stmt.executeUpdate(uQuery);
con.commit();
if(i>0)
System.out.println(i+"rows updated");
 stmt.executeUpdate(uQuery);
}
catch(ClassNotFoundException |SQLException e){
e.printStackTrace();
}
finally{
stmt.close();
con.close();
}
}
}
