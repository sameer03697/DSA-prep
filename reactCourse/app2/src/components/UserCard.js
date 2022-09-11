import React, { useState } from 'react'

function UserCard(props) {
    const [user, setUser] = useState({
        userName: '',
        age: 0
    });

    const onUserNameChange = (event) => {
        event.preventDefault();
        // sameer
        if (event.target.value.trim().length > 0) {

            setUser((prev) => {
                prev.userName = event.target.value;
                return prev
            })
        }
    }

    const onAgeChange = (event) => {
        event.preventDefault();
        // sameer
        if (event.target.value.trim().length > 0) {

            setUser((prev) => {
                prev.age = event.target.value
                return prev
            })
        }
    }

    const onSubmitHandler = (event) => {
        event.preventDefault();
        console.log('Submit is clicked');
        if (typeof props.onAddUser == 'function') {
            props.onAddUser(user);
            setUser({
                userName: '',
                age: 0
            })
        }
    }

    return (
        <form onSubmit={onSubmitHandler}>
            <div>
                <label>
                    Username:
                    <input type="text" value={user.userName} onChange={onUserNameChange} />
                </label>
            </div>
            <div>
                <label>
                    Age:
                    <input type="number" value={user.age} onChange={onAgeChange} />
                </label>
            </div>
            <div>
                <input type="submit" value="Submit" />
            </div>
        </form>
    )
}

export default UserCard;