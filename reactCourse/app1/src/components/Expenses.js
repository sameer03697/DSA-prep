import React from "react";
import ExpenseItem from './ExpenseItem'
import './Expenses.css'


function Expenses(props) {
    let expenses = props.expenses;

    return (<div className='expenses'>
      {expenses.map((item, index) => {
        return <ExpenseItem
          key={index}
          title={item.title}
          amount={item.amount}
          date={item.date}
        />
      })}
        </div>
    );
}
export default Expenses;