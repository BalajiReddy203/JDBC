import java.sql.*;
class UpdateQuery{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
stmt=con.createStatement();
String SqlQuery="update aitscse2a set name= 'Hari priya' where 
rollno='501'";
int noRows=stmt.executeUpdate(SqlQuery);
if(noRows>0){
System.out.println(noRows+" rows updated");
}
else{
System.out.println("Insertion unsuccessful");
}
}
catch(ClassNotFoundException | SQLException e){
e.printStackTrace();
}
finally{
stmt.close();
con.close();
}
}
}
