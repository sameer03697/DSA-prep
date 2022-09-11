import React from 'react'
import {createPortal} from 'react-dom'
function User(props) {
    return (<div>
        <div>{props.userName}
            <div>
                {props.age}
            </div>
        </div>
    </div>)
    
}


export default User;