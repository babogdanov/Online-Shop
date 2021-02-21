# Online Shop

**Motivation**

This is my course project for Object Oriented Programming. The task was to design a complete online store using only the capabilities of C++. It was to be done in 4 increments, starting with the general design (without any functionality), implementing more functionality and refactoring as needed at every increment. It was a very tough project, especially at first, but it did a great job of helping me understand OOP principles.

**Features**

This is a console app in which the user has to first log in, then they choose a category of products and a criteria for sorting them. Hard-coded information about products is then displayed and the user can choose products to add to their cart. After that, the user can review their order- they can order the products, empty the cart , or change their address.

**How to use**

You can download the repo as an archive, extract it somewhere and open Online_Shop.sln with Visual Studio. You should be able to build and run the project after that.

**Issues**

In retrospect, some of my design choices are questionable- it would have been a better idea to declare the Product class as abstract and have each category of products extend it- in the real world each product has some unique characteristics. The AccountFile class is also a bit dodgy- an actual file serving as pseudo-database would have been better. Finally, the workflow is not amazing either- you can rarely go back after picking an action.
