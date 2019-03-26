# edd-medication

The purpose of this project is to have a stepper motor be able to be autonomously controlled in accordance
to whatever day of the week it is, as well a specified time of day. The servo will turn for a certain amount
of time, then stop. The servo WILL NOT move until the next time and date that is specified. As of right now (1/23/19),
there are no near-future plans to have a website where data could be entered to select a day and time, repeating if
necessary, for customization. If there is extra time, a website will be included using PHP, MySQL, and Javascript to send
data to the Arduino so that it can utilize user input for unique persons and their corresponding products.


A website has been created that interacts directly with the arduino and its complimenting components. This website allows users to create an "account" and keep track of their weekly medication dispensing, including dosages, the names of the medications, the days each medication should be taken, and a daily time that the arduino will be activated and utilize the time that the user has set to have their medications dispensed. (3/18/19)


The website, while still functional with the program, will no longer be utilized in tandem completely with the arduino. The arduino will be in charge of keeping time and dispensing the medication after a certain amount of time. (3/26/19)
