create table Adopter (
AdopterID   INT PRIMARY KEY,
Password    CHAR NOT NULL,
Name        CHAR NOT NULL,
Gender      CHAR NOT NULL,
Age         INT NOT NULL,
PhoneNumber   CHAR NOT NULL,
Email       CHAR NOT NULL,
LivingCondition   CHAR NOT NULL,
Address     CHAR NOT NULL
);

create table Tag (
ID      INT PRIMARY KEY,
Name    CHAR NOT NULL,
Content   CHAR NOT NULL
);

create table WishList (
ID       INT PRIMARY KEY,
AdopterID   INT NOT NULL,
EnergyLevel  CHAR NOT NULL,
CoatLength   CHAR NOT NULL,
Color      CHAR NOT NULL,
Size      CHAR NOT NULL
);

create table Shelter (
ID      INT PRIMARY KEY,
Name    CHAR NOT NULL,
Address  CHAR NOT NULL,
Tele    CHAR NOT NULL,
Email   CHAR NOT NULL
);

create table Employee (
ID        INT PRIMARY KEY,
Password  CHAR NOT NULL,
Name      CHAR NOT NULL,
Gender      CHAR NOT NULL,
Age         INT NOT NULL,
ShelterID   INT NOT NULL,
PhoneNumber   CHAR NOT NULL,
Email       CHAR NOT NULL
);

create table RecommendedList (
ID             INT PRIMARY KEY,
AdopterID      INT NOT NULL,
AnimalID       INT NOT NULL
);

create table Post (
PostID INT PRIMARY KEY ,
AdopterID INT NOT NULL,
Context   CHAR NOT NULL,
FileName TEXT,
LikeNum   INT NOT NULL
);

create table Community (
CommunityID INT PRIMARY KEY,
Name CHAR NOT NULL,
NumberOfPost INT NOT NULL
);

create table Orders (
ID  INT PRIMARY KEY, 
AdopterID  INT NOT NULL,
AnimalID   INT NOT NULL,
Status     CHAR NOT NULL,
LikeNum    INT NOT NULL
);

create table Animal (
ID INT PRIMARY KEY, 
ShelterID INT NOT NULL,
Species   CHAR NOT NULL,
Breed    CHAR NOT NULL,
Name CHAR NOT NULL, 
Gender CHAR NOT NULL,
Age    CHAR NOT NULL,
Size   CHAR NOT NULL,
Color  CHAR NOT NULL,
CoatLength    CHAR NOT NULL,
EnergyLevel   CHAR NOT NULL,
FileName TEXT
);

create table Trait (
TagID INT NOT NULL, 
AnimalID INT NOT NULL
);