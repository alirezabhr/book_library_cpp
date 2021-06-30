**A Program For Libraries**\
With this program you can add students, books and records.
All of these are inherited from a class named Object.\
We have 4 main adaptors that are inherited from a record 
adaptor (FixRecordAdaptor / DynamicRecordAdaptor) to handle 
reading and writing records and a string adaptor (FixStrAdaptor /
DynamicStrAdaptor) to handle reading and writing String Fields.
Record adaptors are inherited from Adaptor class.\
If you want to extend the code and add another Object, you should
create a class which inherit from Object class, and implement 
override pure methods. In addition, you should add 2 attributes.
The first one is 'constFileName' which is a type of string and 
you should assign your file name to that. The second one is
'constFieldsName' which is a list of strings. You should write
your class fields name.\
After that you have to add your class configurations in config
class.\
**Dont forget to add your configs in config.txt.**
