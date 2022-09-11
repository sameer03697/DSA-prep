import React, { useState } from 'react';
import UserCard from './components/UserCard'
import UserDisplay from './components/UserDisplay'
function App() {
    const [userList, setUserList] = useState([]);

    const onAddUser = (user) => {
        setUserList((prev) => {
            const prevUsers = [...prev];
            const newUser = {
                userName: user.userName,
                age: user.age,
                id: Math.random().toString()
            }
            // return [...prev,user]//[bhusan,bhusan,bhusan,user]
            return [...prevUsers, newUser]
        })
    }

    return (
        <div>
            I am Sameer!
            <UserCard onAddUser={onAddUser} />
            {JSON.stringify(userList)}
            <UserDisplay userlist={userList} />
        </div>
    )
}

export default App;