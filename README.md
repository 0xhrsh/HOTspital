# IITJ HOSPITAL MANAGEMENT SYSTEM


A platform where all the actions related to the health center are performed. For that, a person has to log in on the platform by his personal username and password. The credentials are verified by the admin. Once the credentials are verified, the user is classified into the following  categories : (1) Admin (2) Patient (3) Receptionist (4) Doctor (5) Pharmacist


## Running Project
The project runs in all environments.
Clone the repository:
```bash
git clone https://github.com/harsh-not-haarsh/HOTspital.git
```

Navigate into repository:
``` bash
cd HOTspital
```

For Windows
```
Login.exe
```
For Linux based systems
```
g++ -o Login login.cpp && ./Login.out
```

To Reset Database
```
cd admin && cd mkrecords && make.bat
```


## Patient :

After logging in, he takes the appointment by informing the convenient time and if the slot is available, the patient is sent to the receptionist for initial diagnosis. After getting the time slot allotted, the patient will be sent to the doctor, will get treatment and/or medicines. If he needs leave, a notification with required verification from the doctor’s side will be sent to the admin. The patient can check his medical record and history anytime he wants with his personal username and password.


## Receptionist :

After getting login credentials verified, a receptionist can maintain the queue for all the patients. The receptionist will check the availability of the doctor and accordingly give appointments to the patients. He will do an initial diagnosis like measuring temperature and weight and pass on this information to the doctor.


## Doctor :

Login credentials will be verified and then the patient will get the treatment and the doctor will write the prescription on the basis of availability of medicines and also of the number of beds occupied and details of all the wards. He can access the inventory of the pharmacy as well as the hospital and update the medical record of the patient which goes into the patient’s personal medical history. The doctor can access the medical records of all the patients. The doctor will also approve a medical certificate for leave if required and notify the admin about it.


## Pharmacist :

After getting login credentials verified, the pharmacist gives medicine and does the dressing and other necessities as prescribed by the doctor. The pharmacist maintains the record of the inventory of the medicines and updates the pharmacy if there is any shortage of medicines.


## Admin :

The admin registers the new students every year and provides and keeps track of the login credentials. The activities of the platform are maintained by the admin. Admin notifies the professors for the leave application of the patient if the patient needs it.

There will be an online discussion forum in which patients can discuss their symptoms and find a cure for it.
