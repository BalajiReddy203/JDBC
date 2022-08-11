import java.sql.*;
class CreateQuery{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
stmt=con.createStatement();
String sqlquery="Create table aitscse2a(Rollno varchar(15),name 
varchar(15),branch varchar(15),address varchar(15),Dreamcompany varchar(15))";
stmt.executeUpdate(sqlquery);
System.out.println("Table created.");
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
