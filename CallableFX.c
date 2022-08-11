import java.sql.*;
class CallableEx{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
String sql="{call getBranch(?,?)}";
CallableStatement cstmt=con.prepareCall(sql);
cstmt.setString(1,"503");
cstmt.registerOutParameter(2,java.sql.Types.VARCHAR);
cstmt.execute();
String branch=cstmt.getString(2);
System.out.println("503 branch is:"+branch);
}
catch(ClassNotFoundException |SQLException e){
e.printStackTrace();
}
 }
}
