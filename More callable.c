import java.sql.*;
class MoreCallable{
public static void main(String args[]) throws Exception{
Connection con=null;
Statement stmt=null;
try{
Class.forName("oracle.jdbc.driver.OracleDriver");
con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE","system","aits");
String sp="{call getDetails(?)}";
CallableStatement cstmt=con.prepareCall(sp);
//cstmt.setString(1,"503");
cstmt.registerOutParameter(1,oracle.jdbc.OracleTypes.CURSOR);
cstmt.execute();
ResultSet rs=(ResultSet)cstmt.getObject(1);
if(rs!=null){
while(rs.next()){
System.out.println("Student Name:"+rs.getString(1));
System.out.println("Student Branch:"+rs.getString(2));
}
}
}
catch(ClassNotFoundException |SQLException e){
e.printStackTrace();
}
 }
}
