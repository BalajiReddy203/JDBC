import java.sql.*;
class DeleteQuery{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
stmt=con.createStatement();
String SqlQuery="delete from aitscse2a where rollno='501'";
int i=stmt.executeUpdate(SqlQuery);
if(i>0){
System.out.println(i+" rows deleted");
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
