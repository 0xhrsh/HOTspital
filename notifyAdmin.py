import sys

message="""Subject: Leave Application

Please grant leave to {A} from {B}/{C} to {D}/{E} 
Regards
Health Center 
IIT Jodhpur
"""

message=message.format(A=sys.argv[1],B=sys.argv[2],C=sys.argv[3],D=sys.argv[4],E=sys.argv[5])

print(message)
import smtplib, ssl
receiver_email="anand.2@iitj.ac.in" 
sender_email="hospital.iitj@gmail.com"
port = 465
password = "#password123"
context = ssl.create_default_context()
with smtplib.SMTP_SSL("smtp.gmail.com", port, context=context) as server:
    server.login(sender_email, password)
    server.sendmail(sender_email, receiver_email, message)
