import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import Product from '../product/product';
import HttpService from '../services/http-service';

const http = new HttpService();

class App extends Component {
    
    constructor(props){
        super(props);
        this.loadData = this.loadData.bind(this);
        this.loadData();
        
    }
    
    loadData = () => {
         http.getProducts().then(products => {
             console.log(products);
         }, err => {
             
         }) ;
    }
    
  render() {
    return (
      
      <div className="App">
        <div className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <h2> Welcome to swag shop</h2>
          </div>    
          <div className="container App-main">
            <div className="row">
            <Product className="col-sm-4" price="4.34" title="Cool Toy Gun" imgUrl="https://cdn.shopify.com/s/files/1/1488/4376/products/salt-gun_1024x1024.png"/>
             <Product className="col-sm-4" price="4.34" title="Cool Toy Gun" imgUrl="https://cdn.shopify.com/s/files/1/1488/4376/products/salt-gun_1024x1024.png"/>
             <Product className="col-sm-4" price="4.34" title="Cool Toy Gun" imgUrl="https://cdn.shopify.com/s/files/1/1488/4376/products/salt-gun_1024x1024.png"/>
            </div>
        </div>
      </div>
    
    );
  }
}

export default App;
