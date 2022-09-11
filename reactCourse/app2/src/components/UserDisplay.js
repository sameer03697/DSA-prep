import React from 'react'
import User from './User'

function UserDisplay(props) {

    let userlist = props.userlist;
    return (<div>
        {
            userlist.map((user) => {
                return <User
                    userName={user.userName}
                    age={user.age}
                    key={user.id}
                />
            })
        }
    </div>

    )
}
export default UserDisplay